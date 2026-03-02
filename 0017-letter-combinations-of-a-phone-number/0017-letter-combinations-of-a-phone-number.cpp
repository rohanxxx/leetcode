class Solution {
public:
    unordered_map<int, string> map = {
        {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, 
        {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}
    };
    void dfs(int index, string cur, string& digits, vector<string>& ans){
        if(cur.size() == digits.size()){
            ans.push_back(cur);
            return;
        }

        for(auto it: map[digits[index]-'0']){
            cur.push_back(it);
            dfs(index+1, cur, digits, ans);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        dfs(0, "", digits, ans);
        return ans;
    }
};