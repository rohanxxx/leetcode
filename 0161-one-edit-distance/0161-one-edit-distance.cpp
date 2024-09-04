class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int ns = s.length();
        int nt = t.length();
        
        if(abs(ns-nt) > 1) return false;
        
        if(ns > nt) return isOneEditDistance(t, s);

        for(int i = 0; i < ns; i++){
            if(s[i] != t[i]){
                if(ns == nt) {
                    return s.substr(i+1) == t.substr(i+1);
                }
                else {
                    return s.substr(i) == t.substr(i+1);
                }
            }
        }

        // return false;
        return (ns+1 == nt);
    }
};