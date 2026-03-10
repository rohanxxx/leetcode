class MinStack {
private:
    vector<pair<int, int>> stack;
public:
    MinStack() {}
    
    void push(int val) {
        if(this->stack.empty()){
            stack.push_back({val, val});
            return;
        }
        int newMin = min((int)this->stack.back().second, val);
        stack.push_back({val, newMin});
    }
    
    void pop() {
        this->stack.pop_back();
    }
    
    int top() {
        return this->stack.back().first;
    }
    
    int getMin() {
        return this->stack.back().second;
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