class MedianFinder {
private: 
    int size;
    vector<int> v;
public:
    MedianFinder() {}
    
    void addNum(int num) {
        int index = lower_bound(this->v.begin(), this->v.end(), num) - this->v.begin();
        this->v.insert(this->v.begin()+index, num);
        this->size = this->v.size();
    }
    
    double findMedian() {
        //odd
        if(size%2) return (double)v[size/2];
        return ((double)v[size/2-1]+v[size/2])*0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */