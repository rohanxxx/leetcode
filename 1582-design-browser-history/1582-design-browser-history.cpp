class BrowserHistory {
public:
    int index, maxForward;
    unordered_map<int, string> history;
    BrowserHistory(string homepage) {
        index = 0; maxForward = index;
        history[index] = homepage;
    }
    
    void visit(string url) {
        history[++index] = url;
        maxForward = index;
    }
    
    string back(int steps) {
        index -= steps;
        if(index < 0) index = 0;
        return history[index];
    }
    
    string forward(int steps) {
        index += steps;
        if(index > maxForward) index = maxForward;
        return history[index];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */