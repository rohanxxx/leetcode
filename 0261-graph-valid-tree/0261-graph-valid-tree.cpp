class Solution {
public:
    /*
    visited: 0 1 2 
    queue: {0,-1}/ {1,0}/ {2,1}/ {3,1}/ {4,1} {3,2}
    */
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> visited(n);
        vector<vector<int>> graph(n);

        //built the graph
        //O(E)
        for(auto it: edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        int components = 0;
        //pair<node, parentNode>
        queue<pair<int, int>> q; 
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                components++;
                q.push({i, -1});
                visited[i] = 1;
                //TC: O(V + 2E)
                while(!q.empty()){
                    int node = q.front().first;
                    int parentNode = q.front().second;

                    q.pop();

                    for(auto adjNode: graph[node]){
                        if(visited[adjNode] == 0){
                            visited[adjNode] = 1;
                            q.push({adjNode, node});
                        }
                        else{
                            if(adjNode != parentNode){
                                return false;
                            }
                        }
                    }
                }
            }
        }

        if(components > 1) return false;

        return true;
    }
};