class MedianFinder {
    vector<int> store;
    int sum = 0;
public:
    // Adds a number into the data structure.
    void addNum(int num)
    {   sum += num;
        store.push_back(num);
    }

    // Returns the median of current data stream
    double findMedian()
    {
        int n = store.size();
        return (double) sum / (double)n;
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */