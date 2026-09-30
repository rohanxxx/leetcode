/*
    undirected graph
    contains exactly one cycle
    nodes are 0 to n-1
    given edges[i] = [node1, node2]
    the distance between two nodes a and b is defined to be the minimum number of edges that are needed to go from a to b
    return an int arr ans of size n where ans[i] is the min dis between ith node and any node in the cycle

    0 - 1 - 2 - 5 - 6
        |   |
        3 - 4
    
*/
class Solution {
public:
    void bfs(int node, vector<int>& ans, vector<int>& indegree, vector<vector<int>>& graph){
        queue<vector<int>> q; 
        q.push({node, 0});
        //ans[node] = 0;
        while(!q.empty()){
            auto it = q.front(); q.pop();
            int curNode = it[0];
            int curDis = it[1];

            for(auto adj: graph[curNode]){
                if(indegree[adj] != 0){
                    continue;
                }
                indegree[adj]--;
                ans[adj] = curDis+1;
                q.push({adj, curDis+1});
            }
        }

        return;
    }

    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);

        for(auto edge: edges){
            indegree[edge[0]]++;
            indegree[edge[1]]++;
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 1){
                q.push(i);
                indegree[i]--;
            }
        }

        while(!q.empty()){
            int node = q.front(); q.pop();
            //then traverse it to it's neighbors
            for(auto adj: graph[node]){
                if(indegree[adj] == 0){
                    continue;
                }
                indegree[adj]--;
                if(indegree[adj] != 1){
                    continue;
                }
                q.push(adj);
                indegree[adj]--;
            }
        }

        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            if(indegree[i] <= 0){
                continue;
            }
            bfs(i, ans, indegree, graph);
        }

        return ans;
    }
};