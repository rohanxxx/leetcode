class Solution {
public:
    void backtrack(int index, vector<vector<int>>& ans, vector<int>& curr, int& k, int target){
        if(target < 0){
            return;
        }
        
        if(curr.size() == k){
            if(target == 0){
                ans.push_back(curr);
            }
            //otherwise terminate 
            return;
        }

        //traverse through 1-9
        for(int i = index; i <= 9; i++){
            target -= i;
            curr.push_back(i);
            
            backtrack(i+1, ans, curr, k, target);
            
            curr.pop_back();
            target += i;
        }

        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> ans;
        backtrack(1, ans, curr, k, n);
        
        return ans;
    }
};