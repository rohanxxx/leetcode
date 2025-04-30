class Solution {
public:
    void backtracking(int index, vector<int> temp, set<vector<int>>& set, vector<int>& nums){
        int n = nums.size();
        set.insert(temp);
        if(index == n){
            return;
        }
        for(int i = index; i < n; i++){
            temp.push_back(nums[i]);
            backtracking(i+1, temp, set, nums);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        set<vector<int>> set;
        backtracking(0, temp, set,nums);
        vector<vector<int>> ans(set.begin(), set.end());
        return ans;
    }
};