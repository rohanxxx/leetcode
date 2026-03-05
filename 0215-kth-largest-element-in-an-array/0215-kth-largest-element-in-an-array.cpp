/*
    n - k = ans Index
    0 1 2 3 4 5
    1 2 3 4 5 6
*/
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto num: nums){
            freq[num]++;
        }

        for(int i = 1e4; i >= -1e4; i--){
            if(freq.find(i) != freq.end()){
                k -= freq[i];
            }
            if(k <= 0) return i;
        }

        return -1;
    }
};