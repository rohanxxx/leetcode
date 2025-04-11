class Solution {
public:
    vector<string> ans;
    void backtrack(int& n, string cur, int left, int right){
        if((int)cur.length() == n*2){
            ans.push_back(cur);
            return;
        }
        if(left < n){
            cur += '(';
            backtrack(n, cur, left+1, right);
            cur.pop_back();
        }
        if(right < left){
            cur += ')';
            backtrack(n, cur, left, right+1);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur = "";
        backtrack(n, cur, 0, 0);
        return ans;
    }
};