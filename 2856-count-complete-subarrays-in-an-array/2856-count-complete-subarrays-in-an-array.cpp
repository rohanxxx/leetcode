/*
    Input: nums = [1,3,1,2,2]
    Output: 4

     0 1 2 3 4
    [1,3,1,2,2]
    1 3 1 2
    1 3 1 2 2
    
    3 1 2
    3 1 2 2

    1 -> 2
    2 -> 2
    3 -> 1
*/
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int> cnt;
        int n = nums.size();
        int right = 0;
        unordered_set<int> distinct(nums.begin(), nums.end());
        int distinct_count = distinct.size();

        for (int left = 0; left < n; left++) {
            if (left > 0) {
                int remove = nums[left - 1];
                cnt[remove]--;
                if (cnt[remove] == 0) {
                    cnt.erase(remove);
                }
            }
            while (right < n && cnt.size() < distinct_count) {
                int add = nums[right];
                cnt[add]++;
                right++;
            }
            if (cnt.size() == distinct_count) {
                res += (n - right + 1);
            }
        }
        return res;
    }
};