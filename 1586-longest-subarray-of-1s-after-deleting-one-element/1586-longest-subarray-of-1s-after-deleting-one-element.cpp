class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxCount = 0;
        int prevCount = 0, curCount = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0 && i + 1 < n && nums[i + 1] == 0) {
                // two zeros in a row: break the bridge
                curCount = 0;
                prevCount = 0;
            }
            else if (nums[i] == 0 && i + 1 < n && nums[i + 1] == 1) {
                // single zero before a ones run: save left run, reset current
                prevCount = curCount;
                curCount = 0;                 // <-- minimal fix #1
            }
            else if (nums[i] == 1) {
                curCount++;
                // combine left run (prevCount) + current run (curCount)
                if (prevCount + curCount > maxCount) {   // <-- minimal fix #2
                    maxCount = prevCount + curCount;
                }
            }
        }

        if (maxCount == n) return maxCount - 1; // all ones: must delete one
        return maxCount;
    }
};