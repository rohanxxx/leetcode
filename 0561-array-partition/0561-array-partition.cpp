/*
    [6,2,6,5,1,2]
    0 1 2 3 4 5
    1 2 2 5 6 6
    (6,6) (2,5) (1,2)
    6 + 2 + 1

    0 1 2 3
    1 2 3 4
    1 + 3 => 4
*/
class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        //TC: O(NLogN)
        //SC: O(LogN)
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        int n = nums.size();
        //TC: O(N/2)
        for(int i = 0; i < n; i+=2) ans += nums[i];
        return ans;
    }
};