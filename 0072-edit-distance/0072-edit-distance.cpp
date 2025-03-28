class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> prev(m+1, 0), cur(m+1, 0);
        for(int j = 0; j <= m; j++) prev[j] = j;
        for(int i = 1; i <= n; i++){
            cur[0] = i;
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1]){
                    cur[j] = prev[j-1];
                    continue;
                }
                int deleteOp = 1+prev[j];
                int insertOp = 1+cur[j-1];
                int replaceOp = 1+prev[j-1];
                cur[j] = min({deleteOp, insertOp, replaceOp});   
            }
            prev = cur;
        }
        return prev[m];
    }
};