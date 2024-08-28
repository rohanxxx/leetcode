class Solution {
public:
    string palindrome(int left, int right, string& s){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }
    string longestPalindrome(string s) {
        string ans = "";
        for(int i = 0; i < s.length(); i++){
            string odd = palindrome(i, i, s);
            string even = palindrome(i, i+1, s);
            if(odd.length() > ans.length()){
                ans = odd;
            }
            if(even.length() > ans.length()){
                ans = even;
            }
        }

        return ans;
    }
};