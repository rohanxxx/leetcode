/*
        0  1 2 3
       [1, 2,3,4]
left.   1, 1,2,6
right  24,12,4,1

24, 12, 8, 6
1.   1. 2. 6

TC: O(2N) SC: O(2N) 
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);

        int left = 1, right = 1;
        for(int i = 1; i < n; i++){
            left = left * nums[i-1];
            ans[i] = ans[i] * left;
        }
        for(int i = n-2; i >= 0; i--){
            right = right * nums[i+1];
            ans[i] = ans[i] * right;
        }

        return ans;
    }
};