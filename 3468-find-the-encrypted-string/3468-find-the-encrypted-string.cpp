class Solution {
public:
    string getEncryptedString(string s, int k) {
        int n = s.length();
        string ans(n, '0');
        for(int i = 0; i < n; i++){
            ans[i] = s[(i+k)%n]; 
        }
        return ans;
    }
};