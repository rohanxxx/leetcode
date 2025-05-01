class Solution {
public:
    int func(int i, int j, string& t1, string& t2){
        if(i == 0 || j == 0){
            return 0;
        }
        
        if(t1[i-1] == t2[j-1]) return 1 + func(i-1, j-1, t1, t2);
        int notTake1 = func(i-1, j, t1, t2);
        int notTake2 = func(i, j-1, t1, t2);
        return max({notTake1, notTake2});
    }
    int longestCommonSubsequence(string t1, string t2) {
        int n = t1.length();
        int m = t2.length();
        //vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        vector<int> prev(m+1, 0);
        for(int i = 1; i <= n; i++){
            vector<int> cur(m+1, 0);
            for(int j = 1; j <= m; j++){
                if(t1[i-1] == t2[j-1]) {
                    cur[j] = 1 + prev[j-1];
                    continue;
                }
                int notTake1 = prev[j];
                int notTake2 = cur[j-1];
                cur[j] = max({notTake1, notTake2});
            }
            prev = cur;
        }
        return prev[m];
    }
};