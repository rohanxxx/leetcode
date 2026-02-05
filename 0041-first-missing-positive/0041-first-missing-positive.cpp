/*
    Input: nums = [1,2,0]
    Output: 3
    
    [1,2,0]
    [-1, -2, 0]
    
    
    Input: nums = [3,4,-1,1]
    Output: 2
    
    [3,4,-1,1]
    [3,4,0,1]
    [-3,4,0,-1]
    
    Input: nums = [7,8,9,11,12]
    Output: 1

*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // marks negative / zero to 0's
        for (int i = 0; i < n; i++) {
            if (nums[i] < 1) nums[i] = 0;
        }

        // marks indexes to negative (presence marking)
        for (int i = 0; i < n; i++) {
            int val = abs(nums[i]);
            if (val >= 1 && val <= n) {
                int index = val - 1;

                if (nums[index] > 0) {
                    nums[index] *= -1;
                } else if (nums[index] == 0) {
                    nums[index] = -(n + 1);  // special negative marker
                }
            }
        }

        // find first missing
        for (int i = 0; i < n; i++) {
            //cout << nums[i] << " ";
            if (nums[i] >= 0) return i + 1;
        }

        return n + 1;
    }
};