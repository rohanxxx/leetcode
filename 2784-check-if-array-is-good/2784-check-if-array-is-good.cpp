/*
     0  1. 2. 3
    [1, 3, 3, 2] true
     -1,-3,-3,2

    [-2, -1, -3] false
     0. 1. 2. 3. 4. 5
    -3,-4, 4,-1,-2, 1]
*/

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n, 0);
        for (int a : nums) {
            if (a >= n) {
                return false;
            }
            if (a < n - 1 && count[a] > 0) {
                return false;
            }
            if (a == n - 1 && count[a] > 1) {
                return false;
            }
            count[a]++;
        }
        return true;
    }
};