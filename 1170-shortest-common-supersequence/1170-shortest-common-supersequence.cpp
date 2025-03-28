class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        for(int j = 0; j <= m; j++) dp[0][j] = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        string ans = "";
        while(n > 0 && m > 0){
            char temp;
            if(str1[n-1] == str2[m-1]){
                temp = str1[n-1];
                ans = temp + ans;
                n--; m--;
            }
            else{
                if(dp[n-1][m] > dp[n][m-1]){
                    temp = str1[n-1];
                    ans = temp + ans;
                    n--;
                }
                else{
                    temp = str2[m-1];
                    ans = temp + ans;
                    m--;
                }
            }
        }

        while(n > 0){
            char temp = str1[n-1];
            ans = temp + ans;
            n--;
        }
        while(m > 0){
            char temp = str2[m-1];
            ans = temp + ans;
            m--;
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
};