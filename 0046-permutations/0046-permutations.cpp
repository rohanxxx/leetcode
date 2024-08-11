class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, vector<int>& current){
        if(current.size() == nums.size()){
            ans.push_back(current);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(find(current.begin(), current.end(), nums[i]) == current.end()){
                current.push_back(nums[i]);
                backtrack(nums, current);
                current.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        backtrack(nums, current);
        return ans;
    }
};