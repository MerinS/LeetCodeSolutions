class MedianFinder {
public:
    int flag = 0;
    priority_queue <int> smallset;
    priority_queue <int,vector<int>,greater<int>> largeset;
    
    MedianFinder() {
    }
    
    void addNum(int num) {
                smallset.push(num);
                largeset.push(smallset.top());
                smallset.pop();
                
                if(largeset.size() > smallset.size()){
                    smallset.push(largeset.top());
                    largeset.pop();
                }
    }
    
    
    double findMedian() {
        if( smallset.size() > largeset.size()){
            return smallset.top();
        }
        else{
            return ((double)smallset.top()+(double)largeset.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
