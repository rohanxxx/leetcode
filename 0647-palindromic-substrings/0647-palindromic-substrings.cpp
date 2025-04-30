class Solution {
public:
    int isPalindrom(int i, int j, string& s){
        int count = 0;
        while(i >= 0 && j < s.length() && s[i] == s[j]){
            i--; j++; count++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;
        for(int i = 0; i < n; i++){
            int odd = isPalindrom(i, i, s);
            int even = isPalindrom(i, i+1, s);
            count += (odd+even);
        }
        return count;
    }
};