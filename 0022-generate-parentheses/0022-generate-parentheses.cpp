class Solution {
public:
    void backtrack(vector<string>& ans, int& n, string cur, int leftCount, int rightCount){
        if(n*2 == (int)cur.size()){
            ans.push_back(cur);
            return;
        }

        if(leftCount < n){
            cur += "(";
            backtrack(ans, n, cur, leftCount+1, rightCount);
            cur.pop_back();
        }
        if(rightCount < leftCount){
            cur += ")";
            backtrack(ans, n, cur, leftCount, rightCount+1);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        backtrack(ans, n, "", 0, 0);
        return ans;
    }
};