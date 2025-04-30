class Solution {
public:
    /*
    bababdddddba
    */
    string isPalindrom(int left, int right, string& s){
        while(left >= 0 && right < s.length() && s[left] == s[right]){
            left--; right++;
        }
        return s.substr(left+1, right-1-left+1-1);
    }

    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        for(int i = 0; i < n; i++){
            string odd = isPalindrom(i, i, s);
            if(ans.size() < odd.size()){
                ans = odd;
            }
            string even = isPalindrom(i,i+1, s);
            if(ans.size() < even.size()){
                ans = even;
            }
        }

        return ans;
    }
};