class Solution {
public:
    void dfs(int val, int& n, vector<int>& ans){
        if(val <= n){
            ans.push_back(val);
        }
        for(int i = 0; i <= 9; i++){
            if(val*10+i > n) return;
            dfs(val*10+i, n, ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i <= 9; i++){
            dfs(i, n, ans);
        }
        return ans;
    }
};