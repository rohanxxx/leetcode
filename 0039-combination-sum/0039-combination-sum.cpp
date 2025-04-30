class Solution {
public:
    void backtrack(int index, set<vector<int>>& ans, vector<int> temp, int target, vector<int>& candidates){
        int n = candidates.size();
        if(target == 0){
            ans.insert(temp);
            return;
        }
        if(target < 0) return;
        for(int i = index; i < n; i++){
            temp.push_back(candidates[i]);
            backtrack(i, ans, temp, target-candidates[i], candidates);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        set<vector<int>> ans;
        backtrack(0, ans, temp, target, candidates);

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};