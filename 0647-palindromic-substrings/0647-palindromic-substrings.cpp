class Solution {
public:
    bool isPalinedrom(int lo, int hi, const string& s){
        while(lo <= hi){
            if(s[lo] != s[hi]) return false;
            lo++; hi--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int countPalinedrome = 0;
        for(int lo = 0; lo < s.length(); lo++){
            for(int hi = lo; hi < s.length(); hi++){
                countPalinedrome += isPalinedrom(lo, hi, s);
            }
        }
        return countPalinedrome;
    }
};