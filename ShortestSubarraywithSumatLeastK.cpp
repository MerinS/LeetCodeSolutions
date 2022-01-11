class Solution {
public:
    int min(int x, int y){
        return x > y ? y : x;
    }
    int shortestSubarray(vector<int>& nums, int k) {
        int min_op  = INT_MAX;
        deque<int> indexes;
        vector <long long int> nums_copy(nums.size(),0);
        int flag     = 0;
        for(int i = 0; i<nums.size();  ++i){
            if(nums[i] >= k) {
                return 1;
            }
            if (i == 0){
                nums_copy[0] = nums[0];
            }
            if(i != 0){
                nums_copy[i] = nums[i] + nums_copy[i-1];
            }
            
            if(nums_copy[i] >= k) {
                min_op = min(i+1,min_op);
                flag   = 1;
            }
            
            while((indexes.size()!= 0) && (nums_copy[i]-nums_copy[indexes.front()]>=k)){
                min_op = min(i - indexes.front(), min_op);
                flag   = 1;
                indexes.pop_front();  
            }
                  
            while(indexes.size()!= 0 && (nums_copy[i] <= nums_copy[indexes.back()])){
                indexes.pop_back();
            }
            
            indexes.push_back(i);
            
        }
        return flag == 1? min_op:-1;
    }
};
