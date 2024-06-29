class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.length();
        for(int i = 1; i <= len/2; i++){
            if(len%i == 0){
                string pattern = "";
                for(int j = 0; j < len/i; j++) pattern += s.substr(0, i);
                if(s == pattern) return true;
            }
        }

        return false;
    }
};