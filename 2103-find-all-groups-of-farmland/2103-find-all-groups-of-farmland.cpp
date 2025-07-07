/*
    [[1,1,1,1,1,1,1,1,1,1,1,1]]
*/
class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        //cout << "n: " << n << endl;
        //cout << "m: " << m << endl;
        vector<vector<int>> ans;
        vector<vector<int>> dir = {{1,0}, {0,1}};
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(land[i][j] == 1 && visited[i][j] == 0){
                    queue<pair<int, int>> q; q.push({i,j});
                    
                    visited[i][j] = 1;

                    vector<int> curLand;
                    curLand.push_back(i);
                    curLand.push_back(j);

                    pair<int, int> prev;
                    while(!q.empty()){
                        int r = q.front().first;
                        int c = q.front().second;
                        
                        prev = {r,c};
                        
                        q.pop();

                        for(auto& it: dir){
                            int adjr = it[0] + r;
                            int adjc = it[1] + c;
                            if(adjr < n && adjc < m){
                                if(land[adjr][adjc] == 1 && visited[adjr][adjc] == 0){
                                    q.push({adjr, adjc});
                                    visited[adjr][adjc] = 1;
                                }
                            } 
                        }
                    }
                    curLand.push_back(prev.first);
                    curLand.push_back(prev.second);
                    
                    ans.push_back(curLand);
                }
            }
        }

        return ans;
    }
};