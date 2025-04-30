class Solution {
public:
    /*
                            [1,2,3]
        [1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]
        [1 2 3]
        [2,3,1]
        [2,1,3] 
    */
    void backtrack(vector<int> cur, vector<vector<int>>& ans, vector<int>& nums, int& n){
        if(cur.size() == n){
            ans.push_back(cur);
            return;
        }
        for(int num: nums){
            if(find(cur.begin(), cur.end(), num) == cur.end()){
                cur.push_back(num);
                backtrack(cur, ans, nums, n);
                cur.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<int> cur;
        vector<vector<int>> ans;
        backtrack(cur, ans, nums, n);
        return ans;
    }
};