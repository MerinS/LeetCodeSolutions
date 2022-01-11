class Solution {
public:
    string orderlyQueue(string S, int K) {
        string op;  
        
        if(K == 1){
            op = S;
            for(int i=1; i<S.size(); ++i){
                string newstr = S.substr(i,S.size()-i)+S.substr(0,i);
                if(op > newstr){
                    op = newstr;
                }
            }
        }
        
        else{
            sort(S.begin(),S.end());
            op = S;
        }
        return op;
    }
};
