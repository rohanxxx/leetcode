class MedianFinder {
    vector<int> nums;
public:
    MedianFinder() {}
    void addNum(int num) {
        if(nums.empty()) nums.push_back(num);
        else nums.insert(lower_bound(nums.begin(), nums.end(), num), num);  
    }
    
    double findMedian() {
        // sort(nums.begin(), nums.end());
        int size = nums.size();
        if(size%2) return (double)nums[size/2];
        return ((double)nums[size/2-1]+nums[size/2])*0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */