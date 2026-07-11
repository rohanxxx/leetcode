/*
    1 - 2
    | \ |
    3.- 4
*/
class Solution {
public:
    int bfs(int node, vector<int>& visited, vector<vector<int>>& graph){
        queue<int> q;
        q.push(node);

        visited[node] = 1;

        int nodeCount = 0;
        int edgeCount = 0;
        while(!q.empty()){
            node = q.front();
            q.pop();

            nodeCount += 1;

            for(auto adj: graph[node]){
                edgeCount += 1;
                if(visited[adj] == 1){
                    continue;
                }

                q.push(adj);
                visited[adj] = 1;
            }
        }

        //check the full component here
        return ((edgeCount/2) == (nodeCount * (nodeCount-1)/2));
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        //step #1: create the graph
        vector<vector<int>> graph(n);
        for(auto it: edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        int count = 0;
        vector<int> visited(n, 0);
        //step #2: traverse the graph for each component alongside with their edge count
        //step #3: use the formula edgeCount == (n * (n-1)/ 2)
        for(int i = 0; i < n; i++){
            if(visited[i] == 0){
                count += bfs(i, visited, graph);
            }
        }

        return count;
    }
};