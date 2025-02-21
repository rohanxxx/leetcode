class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int minVal = INT_MAX;
        int maxVal = INT_MIN;

        for(int num: nums){
            minVal = min(num, minVal);
            maxVal = max(num, maxVal);
        }

        vector<int> count(maxVal - minVal + 1);
        for(int num: nums){
            count[num-minVal]++;
        }

        int remain = k;
        for(int i = count.size()-1; i >= 0; i--){
            remain -= count[i];
            if(remain <= 0){
                return i+minVal;
            }
        }

        return -1;
    }
};