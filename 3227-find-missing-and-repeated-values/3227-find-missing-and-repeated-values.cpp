class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[m].size();
        vector<int> map(n*m+1);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                map[grid[i][j]]++;
            }
        }

        vector<int> ans(2, 0);
        for(int i = 1; i <= n*m; i++){
            if(map[i] == 0){
                ans[1] = i;
            }
            if(map[i] == 2){
                ans[0] = i;
            }
        }

        return ans;
    }
};