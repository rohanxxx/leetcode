class Solution {
public:
    bool isPalindrome(int lo, int hi, string& s){
        while(lo <= hi){
            if(s[lo] != s[hi]) return false;
            lo++; hi--; 
        }
        return true;
    }
    int countSubstrings(string s) {
        int count = 0;
        for(int lo = 0; lo < s.length(); lo++){
            for(int hi = lo; hi < s.length(); hi++){
                count += isPalindrome(lo, hi, s);
            }
        }

        return count;
    }
};