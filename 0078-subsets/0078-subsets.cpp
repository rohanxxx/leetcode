class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, vector<int>& current, int index){
        for(int i = index; i < nums.size(); i++){
            current.push_back(nums[i]);
            ans.push_back(current);
            backtrack(nums, current, ++index);
            current.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        ans.push_back(current);
        backtrack(nums, current, 0);
        return ans;
    }
};