class Solution {
public:
    /*
    bababdddddba
    */
    bool isPalindrom(int left, int right, string& s){
        while(left <= right){
            if(s[left] != s[right]) return false;
            left++; right--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";
        for(int i = 0; i < n; i++){
            for(int j = i; j < n; j++){
                if(isPalindrom(i, j, s)){
                    if(ans.length() < j-i+1){
                        ans = s.substr(i, (j-i+1));
                    }
                }
            }
        }

        return ans;
    }
};