class FreqStack {
public:
    map<int, int> num_freq_map;
    map<int, stack <int> > freq_num_map;
    map<int, int>::iterator it1;
    map<int, stack <int> >::iterator it2;
    int max_freq;
    FreqStack() {
       max_freq = 0;
    }
    
    void push(int x) {
        //printf("push %d\n",x);
        int count;
        if(num_freq_map.find(x) != num_freq_map.end()){
            num_freq_map[x]++;
            count = num_freq_map[x];
            freq_num_map[count].push(x); 
        }
        else{
            num_freq_map[x] = 1;
            freq_num_map[1].push(x);
        }
        if(num_freq_map[x] > max_freq){
            max_freq = num_freq_map[x];
        }
        return;
    }
    
    int pop() {
        int val = freq_num_map[max_freq].top();
        //printf("pop %d \n",val);
        freq_num_map[max_freq].pop();
        num_freq_map[val] = max_freq - 1;
        if(freq_num_map[max_freq].empty()){
            freq_num_map.erase(max_freq);
            max_freq = max_freq - 1;
            //printf("new max freq = %d",max_freq);
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 */
