class MedianFinder {
public:
    priority_queue<int> part1;
    priority_queue<int,vector<int>,greater<int>> part2;
    MedianFinder() {
        part1=priority_queue<int>{};
        part2=priority_queue<int,vector<int>,greater<int>>{};
    }
    
    void addNum(int num) {
        if(part1.size()==0){
            part1.push(num);
            return;
        }

        if(part1.size()>part2.size()){
            if(num<part1.top()){
                part2.push(part1.top());
                part1.pop();
                part1.push(num);
            }
            else{
                part2.push(num);
            }
        }
        else{
            if(num<part1.top()){
                part1.push(num);
            }
            else{
                part2.push(num);
                part1.push(part2.top());
                part2.pop();
            }
        }
    }
    
    double findMedian() {
        if(part1.size()==part2.size()){
            return (double)(part1.top()+part2.top())/2.0;
        }
        else{
            return (double)part1.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */