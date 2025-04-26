class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int left = 0, right = s.length()-1;
        while(left < right){
            while(left < right && !isalnum(s[left])) left++;
            while(left < right && !isalnum(s[right])) right--;
            //cout << "s[left]: " << s[left] << ", s[right]: " << s[right] << endl;
            if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++; right--;
        }
        return true;
    }
};