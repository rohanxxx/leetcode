class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        //O(N)
        //SC: O(N+N)
        vector<int> ans = nums;
        //O(N)
        for(int i = 0; i < n; i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};