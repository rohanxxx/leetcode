class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& candidates, vector<int>& curElements, int curSum, int& target){
        if(curSum > target){
            return;
        }
        if(curSum == target){
            ans.push_back(curElements);
            return;
        }
        for(int i = 0; i < candidates.size(); i++){
            curSum += candidates[i];
            curElements.push_back(candidates[i]);
            backtrack(candidates, curElements, curSum, target);
            curSum -= candidates[i];
            curElements.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curElements;
        backtrack(candidates, curElements, 0, target);
        return ans;
    }
};