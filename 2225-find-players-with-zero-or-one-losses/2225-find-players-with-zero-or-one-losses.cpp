class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int maxi = INT_MIN;
        int mini = INT_MAX;

        //TC: O(N)
        for(auto it: matches){
            maxi = max({maxi, it[0], it[1]});
            mini = min({mini, it[0], it[1]});
        }

        int n = maxi-mini+1;
        //SC: O(K+N)
        vector<vector<int>> bucket(n, vector<int>(2, 0));

        //TC: O(N)
        for(auto it: matches){
            int winner = it[0];
            int loser = it[1];
            bucket[winner-mini][0]++;
            bucket[loser-mini][1]++;
        }

        vector<vector<int>> ans(2);

        //TC: O(K)
        for(int i = 0; i < n; i++){
            if(bucket[i][0] > 0 || bucket[i][1] > 0){
                int key = i + mini;
                if(bucket[i][1] == 0){
                    ans[0].push_back(key);
                }
                if(bucket[i][1] == 1){
                    ans[1].push_back(key);
                }
            }
        }

        return ans;
    }
};