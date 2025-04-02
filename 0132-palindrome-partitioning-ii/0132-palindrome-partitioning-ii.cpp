class Solution {
public:
    bool isPalindrome(int i, int j, string& s){
        // int i = 0, j = s.length();
        while(i <= j){
            if(s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1, 0);
        for(int i = n-1; i >= 0; i--){
            int minCost = INT_MAX;
            for(int j = i; j < s.length(); j++){
                if(isPalindrome(i, j, s)){
                    int cost = 1+dp[j+1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0]-1;
    }
};