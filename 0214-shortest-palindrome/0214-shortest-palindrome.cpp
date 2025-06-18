/*
    a b c d
    d c b a

    0 1 2 3 4 5 6 7
    a a c e c a a a
                  1
    a a a c e c a a

    617 580 811
*/
class Solution {
public:
    string shortestPalindrome(string s) {
        long long prefixMap = 0, suffixMap = 0;
        long long base = 26, power = 1;

        int index = -1;

        int mod = 1e9 + 7;
        int n = s.length();
        for(int i = 0; i < n; i++){
            int val = (s[i]-'a'+1);
            prefixMap = (prefixMap%mod * base%mod)%mod;
            prefixMap = (prefixMap%mod + val)%mod;
            suffixMap = (suffixMap%mod + (val*power%mod))%mod;
            power = (power%mod*base%mod)%mod;

            if(prefixMap == suffixMap) index = i;
        }

        string temp = "";
        if(index != -1) temp = s.substr(index+1);
        reverse(temp.begin(), temp.end());

        return temp+s;
    }
};