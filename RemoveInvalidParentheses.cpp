class Solution {
public:
    bool checkifvalid(string s){
        int count = 0;
        for(int i =0; s[i]!='\0'; ++i){
            if(s[i] == '('){
                count++;
            }
            if(s[i] == ')'){
                count--;
                if(count<0){
                    return false;
                }
            }
        }
        if(count == 0){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool checkifvalid(char val){
        if(val == '(' || val == ')'){
            return true;
        }
        else{
            return false;
        }
    }     
    vector<string> removeInvalidParentheses(string s) {
        queue<string> str_queue;
        str_queue.push(s);
        set<string> str_list;
        set<string>::iterator it;
        vector<string> valid_string;
        str_list.insert(s);
        bool done = false;
        string temp;
        while(!str_queue.empty()){
            s = str_queue.front();
            str_queue.pop();

            if(checkifvalid(s)){
                valid_string.push_back(s);
                done = true;
            }
            if(done){
                continue;
            }
            for(int i =0; s[i]!='\0'; ++i){
                if(checkifvalid(s[i])){
                    temp.clear();
                    for(int k=0; s[k]!='\0';++k){
                        if(k==i){
                            continue;
                        }
                        else{
                            temp += s[k];
                        }
                    }

			   
                    it = str_list.find(temp);
                    if(it==str_list.end()){
                        str_list.insert(temp);
                        str_queue.push(temp);
                    }
                }
            }   
        }
        return valid_string;
    }
};
