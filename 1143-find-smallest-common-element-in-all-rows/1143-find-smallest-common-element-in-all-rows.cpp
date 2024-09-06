class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int n = mat.size();
        // cout << "n: " << n << endl;
        int mini = INT_MAX;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < mat[i].size(); j++){
                mp[mat[i][j]]++;
                if(mp[mat[i][j]] == n){
                    mini = min(mini, mat[i][j]);
                }
            }
        }

        if(mini == INT_MAX) return -1;
        return mini;
    }
};