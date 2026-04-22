class Solution {
public:
    void dfs(int left, int right, string& curr, int& n, vector<string>& ans){
        if(curr.length() == n*2){
            ans.push_back(curr);
            return;
        }
        if(left < n){
            curr.push_back('(');
            dfs(left+1, right, curr, n, ans);
            curr.pop_back();
        }
        if(right < left){
            curr.push_back(')');
            dfs(left, right+1, curr, n, ans);
            curr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string curr = "";
        vector<string> ans;
        dfs(0, 0, curr, n, ans);
        return ans;
    }
};