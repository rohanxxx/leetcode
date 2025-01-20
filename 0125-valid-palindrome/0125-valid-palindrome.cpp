class Solution {
public:
    bool isPalindrome(string s) {
        int j = 0;
        for(int i = 0; i < s.length(); i++){
            if(isalpha(s[i])||isdigit(s[i])) {
                s[j++] = tolower(s[i]);
            }
        }
        
        int left = 0, right = j-1;
        while(left < right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
};