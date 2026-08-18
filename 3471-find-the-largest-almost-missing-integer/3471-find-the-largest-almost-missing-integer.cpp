class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        if (n == 0) {
            return -1;
        }
        if (n == 1) {
            return nums[0];
        }

        // k == n: only 1 subarray exists, every element qualifies
        if (k == n) {
            int ans = -1;
            for (auto num : nums) {
                ans = max(ans, num);
            }
            return ans;
        }

        // k == 1: need frequency == 1
        if (k == 1) {
            unordered_map<int, int> freq;
            for (auto num : nums) {
                freq[num]++;
            }
            int ans = -1;
            for (auto& [num, cnt] : freq) {
                if (cnt == 1) {
                    ans = max(ans, num);
                }
            }
            return ans;
        }

        // 1 < k < n: only endpoints can appear in exactly 1 window
        unordered_set<int> set;
        set.insert(nums[0]);
        set.insert(nums.back());

        if (nums[0] == nums.back()) {
            set.erase(nums[0]);  // both endpoints same value = appears in 2 windows, disqualified
        }

        for (int i = 1; i < n - 1; i++) {
            if (set.find(nums[i]) != set.end()) {
                set.erase(nums[i]);
            }
        }

        int ans = -1;
        for (auto it : set) {
            ans = max(ans, it);
        }

        return ans;
        // TC: O(n)
        // SC: O(1) — set holds at most 2 elements
    }
};