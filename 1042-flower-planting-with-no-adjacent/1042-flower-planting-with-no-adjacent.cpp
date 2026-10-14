/*
    n -> gardens 1 through n
    paths[i] = [xi, yi] bidirectional
    in each garden you want to plant one of the 4 types of flowers
    all gardens have at most 3 path coming into or leaving it

    task: choose a flower type for each garden such that for any two gardens connected by a path they have different types of flowers 

    flower types are denoted 1 2 3 4

    return arr ans[i] is the type where i+1 th garden

    ans[i] maps to i+1th garden

    n = 3 3 gardern 1 2 3

    1 - 2
     \ /
      3

    1 - 2
    3 - 4

         -------
        |       |
    1 - 2 - 3 - 4 
    |       |   |
    ------------

    (1,-1)x,(2,1)x,(3,1),(4,1)


    1 2 3 4
    0 1 2 3 
*/
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        //initially everything is marked 0
        vector<int> ans(n, 0);
        //first build the graph
        //1-index based
        //TC: O(V+E)
        vector<vector<int>> graph(n+1);
        vector<int> visited(n+1, 0);
        for(auto it: paths){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        queue<int> q;
        for(int start = 1; start <= n; start++){
            if(visited[start] == 1){
                continue;
            }
            q.push(start);
            visited[start] = 1;
            while(!q.empty()){
                vector<int> mark(5, 0);
                int node = q.front(); q.pop();
                //look at the adj neighbors with marking
                for(auto adj: graph[node]){
                    if(visited[adj] == 1){
                        //also mark it
                        //ans[parent-1] marked value of that node
                        mark[ans[adj-1]] = 1;
                        continue;
                    }
                    //mark the adj if it is already assigned
                    //ans[parent-1] marked value of that node
                    mark[ans[adj-1]] = 1;
                    q.push(adj);
                    visited[adj] = 1;
                }

                //mark the current node
                //TC: O(4)
                for(int i = 1; i < 5; i++){
                    if(mark[i] == 0){
                        ans[node-1] = i;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};