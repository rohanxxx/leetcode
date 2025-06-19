/*

[0,1,0]
[0,1,0]
[0,1,0]
[0,1,0]
[0,1,0]

*/
class Solution {
public:
    int n, m;
    int dfs1(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& visited){
        if(i < n && j < m && mat[i][j] == 1) {
            visited[i][j] = 1;
            return 1 + dfs1(i,j+1, mat, visited);
        }
        return 0;
    }
    int dfs2(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& visited){
        if(i < n && j < m && mat[i][j] == 1) {
            visited[i][j] = 1;
            return 1 + dfs2(i+1,j, mat, visited);
        }
        return 0;
    }
    int dfs3(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& visited){
        if(i < n && j < m && mat[i][j] == 1) {
            visited[i][j] = 1;
            return 1 + dfs3(i+1,j+1, mat, visited);
        }
        return 0;
    }
    int dfs4(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& visited){
        if(i < n && j >= 0 && mat[i][j] == 1) {
            visited[i][j] = 1;
            return 1 + dfs4(i+1,j-1, mat, visited);
        }
        return 0;
    }
    int longestLine(vector<vector<int>>& mat) {
        n = mat.size(); m = mat[0].size();
        
        int len = 0;
        //SC: O(4*N*M)
        vector<vector<int>> visitedHor(n, vector<int>(m, 0));
        vector<vector<int>> visitedVer(n, vector<int>(m, 0));
        vector<vector<int>> visitedDag(n, vector<int>(m, 0));
        vector<vector<int>> visitedAntiDag(n, vector<int>(m, 0));

        //TC: O(3*N*M)
        //O(N)
        for(int i = 0; i < n; i++){
            //O(M)
            for(int j = 0; j < m; j++){
                if(mat[i][j] == 0) continue;
                if(visitedHor[i][j] == 0){
                    len = max(len, dfs1(i, j, mat, visitedHor));
                }
                if(visitedVer[i][j] == 0){
                    len = max(len, dfs2(i, j, mat, visitedVer));
                }
                if(visitedDag[i][j] == 0){
                    len = max(len, dfs3(i, j, mat, visitedDag));
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = m-1; j >= 0; j--){
                if(mat[i][j] == 0) continue;
                if(visitedAntiDag[i][j] == 0){
                    len = max(len, dfs4(i, j, mat, visitedAntiDag));
                }
            }
        }

        return len;
    }
};