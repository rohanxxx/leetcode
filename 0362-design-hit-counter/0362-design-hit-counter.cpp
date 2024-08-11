class HitCounter {
private:
    queue<int> hits;
public:
    //initializes the object
    HitCounter() {
    
    }
    
    //records a hit happened at the timeStamp
    void hit(int timestamp) {
        this->hits.push(timestamp);
    }
    
    //returns the number of hits in the past 5 minutes from timestamp
    int getHits(int timestamp) {
        while(!this->hits.empty()){
            int hitTime = hits.front();
            int difference = timestamp - hitTime;
            if(difference >= 300) {
                this->hits.pop();
            }
            else return this->hits.size();
        }
        return 0;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter* obj = new HitCounter();
 * obj->hit(timestamp);
 * int param_2 = obj->getHits(timestamp);
 */