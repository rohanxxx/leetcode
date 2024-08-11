class Solution {
public:
    vector<vector<int>> combinations;
    void backtrack(vector<int>& candidates, vector<int>& combination, int sum, int& target, int index){
        if(sum == target){
            combinations.push_back(combination);
            return;
        }

        if(sum > target) return;

        for(int i = index; i < candidates.size(); i++){
            combination.push_back(candidates[i]);
            backtrack(candidates, combination, candidates[i]+sum, target, i);
            combination.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combination;
        backtrack(candidates, combination, 0, target, 0);
        return combinations;
    }
};