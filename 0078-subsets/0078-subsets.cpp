class Solution {
public:
    void dfs(int index, vector<int>& temp, vector<vector<int>>& ans, vector<int>& nums){
        ans.push_back(temp);
        if(temp.size() == nums.size()){
            return;
        } 
        for(int i = index; i < nums.size(); i++){
            temp.push_back(nums[i]);
            dfs(i+1, temp, ans, nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        dfs(0, temp, ans, nums);
        return ans;
    }
};