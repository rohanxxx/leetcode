class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& candidates, vector<int>& curElements, int curSum, int& target, int index){
        if(curSum > target){
            return;
        }
        if(curSum == target){
            ans.push_back(curElements);
            return;
        }
        for(int i = index; i < candidates.size(); i++){
            curElements.push_back(candidates[i]);
            backtrack(candidates, curElements, curSum + candidates[i], target, i);
            curElements.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curElements;
        backtrack(candidates, curElements, 0, target, 0);
        return ans;
    }
};