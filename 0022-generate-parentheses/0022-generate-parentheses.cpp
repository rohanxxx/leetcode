class Solution {
public:
    vector<string> ans;
    void backtrack(int n, string cur, int left, int right){
        if(cur.length() == n*2){
            ans.push_back(cur);
            return;
        }
        if(left < n){
            cur.push_back('(');
            backtrack(n, cur, left+1, right);
            cur.pop_back();
        }
        if(right < left){
            cur.push_back(')');
            backtrack(n, cur, left, right+1);
            cur.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        backtrack(n, "", 0, 0);
        return ans;
    }
};