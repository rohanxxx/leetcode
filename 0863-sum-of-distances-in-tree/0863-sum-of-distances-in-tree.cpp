/*
    return an ans of length n where ans[i] is the sum of the distances between the ith node in the tree and all the other node

    n = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
                         
                          5
                          |
                      3 - 2 - 0 - 1
                          |
                          4

    ans =   8 12 6 10 10 10
            0 1  2  3  4  5 
*/
class Solution {
public:
    int N;
    void dfs(int node, int parent, vector<int>& count, vector<int>& ans, vector<vector<int>>& graph){
        for(auto adjNode: graph[node]){
            if(adjNode != parent){
                dfs(adjNode, node, count, ans, graph);
                count[node] += count[adjNode];
                ans[node] += (ans[adjNode] + count[adjNode]);
            }
        }
    }
    void dfs2(int node, int parent, vector<int>& count, vector<int>& ans, vector<vector<int>>& graph){
        for(auto adjNode: graph[node]){
            if(adjNode != parent){
                ans[adjNode] = ans[node] - count[adjNode] + (N-count[adjNode]);
                dfs2(adjNode, node, count, ans, graph);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N = n;
        vector<vector<int>> graph(n);
        for(auto it: edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<int> count(n, 1);
        vector<int> ans(n, 0);
        dfs(0, -1, count, ans, graph);
        dfs2(0, -1, count, ans, graph);
        return ans;
    }
};