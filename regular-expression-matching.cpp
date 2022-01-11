class Solution {
public:
    bool isMatch(string s, string p) {
        int s_size = s.size();
        int p_size = p.size();
        bool flag_array[s_size+1][p_size+1];
        flag_array[0][0] = true;
        for(int i = 1; i < p_size+1; ++i){
            if(p[i-1] == '*'){
                if(i == 1){
                    //if there's a * at the start of the pattern
                    return false;
                }
                else{
                    flag_array[0][i] = flag_array[0][i-2];
                }
            }
            else{
                flag_array[0][i] = false;
            }
        }
        
        for(int i= 0 ; i < p_size +1 ; ++i){
            printf("%d ",flag_array[0][i]);
        }
        printf("\n");
        
        for(int j = 1; j< s_size+1; ++j){
            flag_array[j][0] = false;
        }
        
        for(int i= 0 ; i < s_size; ++i){
            for(int j= 0 ; j < p_size; ++j){
                if(p[j] == s[i] || p[j] == '.'){
                    flag_array[i+1][j+1] = flag_array[i][j];
                }
                else if(p[j] == '*'){
                    flag_array[i+1][j+1] = flag_array[i+1][j-1];
                    if(s[i] == p[j-1] || p[j-1]== '.'){
                        flag_array[i+1][j+1] = (flag_array[i+1][j+1])|(flag_array[i][j+1]);
                    }
                }
                else{
                    flag_array[i+1][j+1] = false;
                }
            }
        }
        for(int i= 0 ; i < s_size +1 ; ++i){
            for(int j= 0 ; j < p_size+1 ; ++j){
                printf("%d ",flag_array[i][j]);
            }
            printf("\n");
        }
        return flag_array[s_size][p_size];;
    }
};
