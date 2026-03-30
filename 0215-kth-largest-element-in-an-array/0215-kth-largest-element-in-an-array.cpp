/*
    n - k = ans Index
    0 1 2 3 4 5
    1 2 3 4 5 6
*/
class Solution {
public:
    //TC: O(N+(Max-Min)) = O(N+M)
    //SC: O(N)
    int findKthLargest(vector<int>& nums, int k) {
        int maxElement = INT_MIN;
        int minElement = INT_MAX;
        //SC: O(N)
        unordered_map<int, int> freq;
        //TC: O(N)
        for(auto num: nums){
            freq[num]++;
            maxElement = max(maxElement, num);
            minElement = min(minElement, num);
        }

        //TC: O(MAX-MIN)
        for(int i = maxElement; i >= minElement; i--){
            if(freq.find(i) != freq.end()){
                k -= freq[i];
            }
            if(k <= 0) return i;
        }

        return -1;
    }
};