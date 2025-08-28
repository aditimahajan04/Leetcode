class MinStack {
public:
    stack<int>s,mins;
    
    void push(int val) {
        s.push(val);

        if(mins.size()==0 || val<=mins.top()){
            mins.push(val);
        }
    }
    
    void pop() {
        if(mins.top()==s.top()){
            mins.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mins.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */