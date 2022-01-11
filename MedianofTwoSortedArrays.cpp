class Solution {
public:
    int max(int x,int y){
        return x>y ? x:y;
    }
    
    int min(int x, int y){
        return x<y ? x:y;
    }
    
    double avg(int x,int y){
        return ((double)x + (double)y)/2; 
    }
   
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double op;
        if(nums1.size() > nums2.size()){
            vector<int> tmp;
            tmp = nums1;
            nums1 = nums2;
            nums2 = tmp;
        }
        
        int m = nums1.size();
        int n = nums2.size();
        int ilow = 0;
        int iup = m;
        while(ilow<=iup){
            int i = (ilow+iup)/2;
            int j = ((m+n)/2)-i;
            int nums1low, nums2high, nums2low, nums1high;
        
            nums1low   = ((i == 0) ? INT_MIN  : nums1[i-1]);
            nums2high  = ((j == n) ? INT_MAX : nums2[j]);
            nums2low   = ((j == 0) ? INT_MIN  : nums2[j-1]);
            nums1high = ((i == m) ?INT_MAX : nums1[i]);
        
            int flag1=0, flag2=0;
            if(nums1low <= nums2high){
                flag1 = 1;
            }
            if(nums2low <= nums1high){
                flag2 = 1;
            }
            cout<<"\n"<<flag1<<flag2;

            if(flag1 == 1 && flag2 == 1){
                if(((m+n) % 2) == 1){
                    return min(nums2high,nums1high);
                }
                else{
                    return avg(max(nums1low,nums2low),min(nums1high,nums2high));
                }
            }
            else if (flag1 == 0){
                iup-=1;
            }
            else{
                ilow+=1;
            }
        }
        return 1.222;
        
    }
};
