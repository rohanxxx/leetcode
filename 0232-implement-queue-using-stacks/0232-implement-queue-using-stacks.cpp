class MyQueue {
private:
    stack<int> inputStack, outputStack;
public:
    MyQueue() {}
    
    void push(int x) {
        inputStack.push(x);
    }
    
    int pop() {
        int ret;
        if(outputStack.empty()){
            while(!inputStack.empty()){
                ret = inputStack.top();
                inputStack.pop();
                outputStack.push(ret);
            }
        }

        if(outputStack.empty()) return -1;
        
        ret = outputStack.top(); outputStack.pop(); 
        return ret;
    }
    
    int peek() {

        int ret;
        if(outputStack.empty()){
            while(!inputStack.empty()){
                ret = inputStack.top();
                inputStack.pop();
                outputStack.push(ret);
            }
        }

        if(outputStack.empty()) return -1;
        
        ret = outputStack.top();
        return ret;

    }
    
    bool empty() {
        if(inputStack.empty() && outputStack.empty()) return true;
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */