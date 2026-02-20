class Solution {
public:
    bool isPalindrome(string& s, int left, int right){
        while(left <= right){
            if(s[left] != s[right]) return false;
            left++; right--;
        }
        return true;
    }
    void backtrack(int left, string& s, vector<string>& str, vector<vector<string>>& ans){
        if(left >= s.length()){
            ans.push_back(str);
            return;
        }
        
        for(int right = left; right < s.length(); right++){
            if(isPalindrome(s, left, right)){
                str.push_back(s.substr(left, right-left+1));
                backtrack(right+1, s, str, ans);
                str.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<string> str;
        vector<vector<string>> ans;
        backtrack(0, s, str, ans);
        return ans;
    }
};