class Solution {
public:
    int dfs(int i, const int& n, string& s){
        if(i >= n){
            return 0;
        }
        if(i == n-1){
            return 1;
        }
        int singleDigit = s[i]-'0';
        int doubleDigit = singleDigit*10+(s[i+1]-'0');
        
        int count = 0;
        if(singleDigit != 0){
            //for single digit case
            count += dfs(i+1, n, s);
        }
        if(singleDigit != 0 && doubleDigit <= 26){
            //for double digit case
            count += dfs(i+2, n, s);
        }
        return count;
    }
    int numDecodings(string s) {
        int n = (int)s.length();
        if(s[0] == '0'){
            return 0;
        }
        return 1+dfs(0, n, s);
    }
};