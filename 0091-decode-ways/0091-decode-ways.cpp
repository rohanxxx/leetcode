class Solution {
public:
    int numDecodings(string s) {
        int n = (int)s.length();

        //if(s[0] == '0') return 0;
        //if(n == 1) return 1;

        vector<int> dp(n, 0);

        // Base case — no ternary, plain if/else
        if(s[n-1] != '0'){
            dp[n-1] = 1;
        }

        for(int i = n-2; i >= 0; i--){
            if(s[i] == '0'){
                continue; // dp[i] stays 0
            }

            int singleDigit = s[i] - '0';
            int doubleDigit = singleDigit * 10 + (s[i+1] - '0');

            int count = 0;

            // single digit case — always use dp[i+1]
            count += dp[i+1];

            // double digit case
            if(doubleDigit >= 10 && doubleDigit <= 26){
                if(i+2 >= n){
                    count++;
                } else {
                    count += dp[i+2];
                }
            }

            dp[i] = count;
        }
        return dp[0];
    }
};