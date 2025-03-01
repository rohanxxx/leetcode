class Solution {
public:
    bool isPalindrome(string& s, int left, int right){
        while(left < right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
    void backtrack(vector<vector<string>>& ans, string& s, int left, vector<string>& cur){
        if(left == s.length()){
            ans.push_back(cur);
            return;
        }
        for(int right = left; right < s.length(); right++){
            if(isPalindrome(s, left, right)){
                cur.push_back(s.substr(left, right-left+1));
                backtrack(ans, s, right+1, cur);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> cur;
        vector<vector<string>> ans;
        backtrack(ans, s, 0, cur);
        return ans;
    }
};