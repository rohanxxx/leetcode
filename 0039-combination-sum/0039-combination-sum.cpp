class Solution {
    /*
        array with distinct input of integers 
        and we have a target integer

        from the arr return a list of unique combinations of candidates where the chosen number
        sum to the target.

        so the same number can be picked multiple times
        if(sum > target){
            return;
        }
        if(sum == target){
            ans.push_back(temp);
        }
        for(int i = 0; i < n; i++){
            temp.push_back(nums[i]);
            backtrack(sum+nums[i], target, candidates);
            temp.pop_back();
        }
    */
public:
    void backtrack(int index, int target, vector<int> cur, vector<vector<int>>& ans, vector<int>& cand){
        if(target == 0){
            ans.push_back(cur);
            return;
        }

        if(target < 0){
            return;
        }

        for(int i = index; i < cand.size(); i++){
            cur.push_back(cand[i]);
            backtrack(i, target-cand[i], cur, ans, cand);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        backtrack(0, target, {}, ans, candidates);
        return ans;
    }
};