class MyStack {
private:
    //SC: O(N)
    vector<int> stack;
public:
    MyStack() {}
    //TC: O(1)
    void push(int x) {
        stack.push_back(x);
    }
    
    //TC: O(1)
    int pop() {
        int res = top();
        stack.pop_back();
        return res;
    }
    //TC: O(1)
    int top() {
        return stack.back();
    }
    //TC: O(1)
    bool empty() {
        if(stack.size() == 0) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */