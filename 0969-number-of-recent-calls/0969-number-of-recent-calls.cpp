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
        lastPing = t; q.push(t);
        if(lastPing - q.front() <= 3000){
            return q.size();
        }
        else{
            while(lastPing - q.front() > 3000){
                q.pop();
            }
            return this->q.size();
        }
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */