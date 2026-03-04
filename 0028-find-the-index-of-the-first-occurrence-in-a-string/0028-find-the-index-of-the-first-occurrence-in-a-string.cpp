class Solution {
public:
    vector<int> createLPS(string& s, int& m){
        vector<int> lps(m, 0);
        int i = 1, len = 0;
        while(i < m){
            if(s[len] == s[i]){
                len++;
                lps[i] = len;
                i++; 
            }
            else{
                if(len != 0){
                    //fall back
                    len = lps[len-1];
                }
                else{
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    int stringMatch(string& s1, string& s2, int& n, int& m, vector<int>& lps){
        int j = 0, i = 0;
        while(i < n){
            if(s1[i] == s2[j]){
                i++; j++;
                if(j == m){
                    return i-j;
                }
            }
            else{
                if(j != 0){
                    j = lps[j-1];
                }
                else{
                    j = 0;
                    i++;
                }
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> lps = createLPS(needle, m);
        return stringMatch(haystack, needle, n, m, lps);
    }
};