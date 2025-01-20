class Solution {
public:
    bool isPalindrome(string s) {
        int j = 0;
        for(int i = 0; i < s.length(); i++){
            if(isalpha(s[i])||isdigit(s[i])) {
                s[j++] = tolower(s[i]);
            }
        }
        // cout << "s: " << s << endl;
        // cout << "s[j]: " << s[j] << endl;
        int left = 0, right = j-1;
        while(left < right){
            if(s[left] == s[right]){}
            else {
                // cout << "left: " << left << endl;
                // cout << "right: " << right << endl;
                return false; 
            }
            left++;
            right--;
        }
        return true;
    }
};