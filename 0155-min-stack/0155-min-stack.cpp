class MinStack {
private:
    vector<pair<int, int>> stack;
public:
    MinStack() {}
    void push(int val) {
        if(!stack.empty()){
            int minSoFar = stack.back().second;
            stack.push_back({val, min(val, minSoFar)});
            return;
        }
        stack.push_back({val, val});
    }
    
    void pop() {
        if(stack.empty()){
            return;
        }
        stack.pop_back();
    }
    
    int top() {
        if(stack.empty()){
            return INT_MIN;
        }
        return stack.back().first;
    }
    
    int getMin() {
        return stack.back().second;
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