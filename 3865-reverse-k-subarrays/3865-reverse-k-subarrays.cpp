/*
    partition into k contiguous subarr of equal len and then reverse each subarr
    it is guaranteed that n % k == 0

                   0 1 2 3 4 5    
    Input: nums = [1,2,4,3,5,6], k = 3
    Output: [2,1,3,4,6,5]


*/
class Solution {
public:
    vector<int> reverseSubarrays(vector<int>& nums, int k) {
        vector<int> ans;

        int n = nums.size();
        int chunk = n / k;
        for(int i = 0; i < n; i+=chunk){
            for(int j = i+chunk-1; j >= i; j--){
                ans.push_back(nums[j]);
            }
        }

        return ans;
    }
};