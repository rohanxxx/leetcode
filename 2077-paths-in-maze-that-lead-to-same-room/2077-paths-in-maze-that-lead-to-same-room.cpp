class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        vector<vector<int>> adj(n+1,vector<int>(n+1,0));
        int result=0;
        for(int i=0;i<corridors.size();i++) {
            adj[corridors[i][0]][corridors[i][1]]=1;
            adj[corridors[i][1]][corridors[i][0]]=1;
        }
        
        for(int i=1;i<=n;i++) {
            for(int j=i+1;j<=n;j++) {
                if(adj[i][j]) {
                    for(int k=j+1;k<=n;k++) {
                        if(adj[j][k] && adj[k][i]) {
                            result++;
                        }
                    }
                }
            }
        }
        return result;
    }
};