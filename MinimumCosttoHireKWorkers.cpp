class Solution {
public:
    struct Workerinfo{
        int index;
        int quality;
        double ratio;
    };
    
    static bool compareInterval(Workerinfo w1, Workerinfo w2) { 
        return (w1.ratio < w2.ratio); 
    } 
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        Workerinfo * vals = new Workerinfo[quality.size()]; 
        for(int i=0 ; i<quality.size() ; ++i){
            vals[i].index = i;
            vals[i].quality = quality[i];
            vals[i].ratio =  ((double)wage[i]/(double)quality[i]);
            // printf("%d %d %f \n",vals[i].index,vals[i].quality,vals[i].ratio); 
        }
        sort(vals, vals+quality.size(), compareInterval); 
        
      
        priority_queue <int> ququality;
        int i = 0;
        int sum = 0;
        double ans = INT_MAX;
        while(i < quality.size()){
            sum += vals[i].quality;
            ququality.push(vals[i].quality);
            
            if(ququality.size() > K){
                sum -= ququality.top();
                ququality.pop();
            }
            
            
            if(ququality.size() == K){
                double temp = sum * vals[i].ratio;
                ans = min(ans, temp);
            }
            
            ++i;
        }
        return ans;
    }
};
