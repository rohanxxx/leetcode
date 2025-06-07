/*
    nums = [1,1,2,1,1], k = 3
    
    [1,1,2,1,1]

    nums = [2,2,2,1,2,2,1,2,2,2], k = 2
     0 1 2 3 4 5 6 7 8 9
      [2,2,2,1,2,2,1,2,2,2]
    1) 2 2 2 1 2 2 1
    2) 2 2 2 1 2 2 1 2
    3) 2 2 2 1 2 2 1 2 2
    4) 2 2 2 1 2 2 1 2 2 2
    5) 2 2 1 2 2 1 2 2 2
    6) 2 2 1 2 2 1 2 2

*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int curSum = 0, count = 0;
        //{sum, freq}
        unordered_map<int, int> freq;
        freq[0] = 1;
        for(int i = 0; i < n; i++){
            curSum += (nums[i] % 2);
            if(freq[curSum-k]) count += freq[curSum-k];
            freq[curSum]++;
        }
        return count;
    }
};