class Solution {
public:
    int maxOutput(int a, int b){
        int op = a>b?a:b;
        return op;
    }
    int maxProfit(int k, vector<int>& prices) {
        int x = prices.size();
        if(x == 0 || x == 1){
            return 0;
        }
        int outProfit[k+1][x];   
        for(int i =0; i < k+1; ++i){
            outProfit[i][0] = 0;
        }
        
        for(int j =0; j < x;  ++j){
            outProfit[0][j] = 0;
        }
        for(int i=1 ; i<=k ; ++i){
            int tmpMax = -prices[0];
            for(int j=1; j< x; ++j){
                outProfit[i][j]  = maxOutput(outProfit[i][j-1], (prices[j]+ tmpMax)); //decide between not selling the jth
                                                                                      //and selling jth
                tmpMax           = maxOutput(tmpMax, outProfit[i-1][j-1] - prices[j]); // decide on buying at jth and moving on 
            }
        }
        return outProfit[k][x-1];
    }
};
