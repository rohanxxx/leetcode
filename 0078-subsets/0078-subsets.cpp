class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(int index, int& n, vector<int> cur, vector<int>& nums){
        ans.push_back(cur);
        if(index == n) return;
        for(int i = index; i < n; i++){
            cur.push_back(nums[i]);
            backtrack(i+1, n, cur, nums);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> cur;
        backtrack(0, n, cur, nums);
        return ans;
    }
};