class Solution {
public:
    vector<vector<int>> combination;
    void backtrack(int remain, int start, vector<int>& candidates, vector<int>& sequence){
        if(remain == 0) {
            combination.push_back(sequence);
            return;
        }
        if(remain < 0) return;
        for(int i = start; i < candidates.size(); i++){
            sequence.push_back(candidates[i]);
            backtrack(remain-candidates[i], i, candidates, sequence);
            sequence.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sequence;

        backtrack(target, 0, candidates, sequence);

        return combination;
    }
};