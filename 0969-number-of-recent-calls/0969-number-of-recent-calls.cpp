class RecentCounter {
public:
    int lastPing = -1;
    queue<int> q;
    RecentCounter() {}
    
    int ping(int t) {
        if(q.empty()){
            lastPing = t;
            q.push(t);
            return 1;
        }
        q.push(t);
        while(t - q.front() > 3000){
            q.pop();
        }
        return (int)q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */