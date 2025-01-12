class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, vector<int>& current){
        if(current.size() == nums.size()){
            ans.push_back(current);
            return;
        }

        for(int& num: nums){
            // if not found then push it to the current vector
            if(find(current.begin(), current.end(), num) == current.end()){
                current.push_back(num);
                backtrack(nums, current);
                current.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        backtrack(nums, current);
        return ans;
    }
};