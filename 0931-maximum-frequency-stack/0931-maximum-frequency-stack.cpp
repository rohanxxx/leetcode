class FreqStack {
public:
    int maxFreq;
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group;
    
    FreqStack() {
        maxFreq = 0;
    }
    
    void push(int val) {
        // freq[val]++;
        maxFreq = max(maxFreq, ++freq[val]);
        group[freq[val]].push(val);
    }
    
    int pop() {
        int mostFreqElement = group[maxFreq].top();
        group[maxFreq].pop();
        freq[mostFreqElement]--;
        if(group[maxFreq].empty()){
            maxFreq--;
        }
        return mostFreqElement;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */