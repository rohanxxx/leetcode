/*
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

  0  1  2  3 4 5 6  7
[-4,-3,-2,-7,8,2,3,-1]

*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(auto& num: nums){
            if(nums[abs(num)-1] > 0) nums[abs(num)-1] *= (-1);
        }
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(nums[i] > 0) ans.push_back(i+1); 
        }
        return ans;
    }
};