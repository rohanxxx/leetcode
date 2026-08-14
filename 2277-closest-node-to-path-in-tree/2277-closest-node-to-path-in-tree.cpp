class Solution {
public:
    int dfs(vector<vector<int>>& graph, int node, int parent, int x, int y){
        int found = INT_MIN;
        if(node == x || node == y){
            found = node;
        }

        int count = 0;
        if(found != INT_MIN){
            count = 1;
        }

        for(auto adjn: graph[node]){
            if(adjn == parent){
                continue;
            }
            int ret = dfs(graph, adjn, node, x, y);
            if(ret != INT_MIN){
                count++;
                found = ret;
                if(count == 2){
                    return node;      // both x and y converge here — this is the LCA
                }
            }
        }

        return found;   // INT_MIN if neither found, or the single found node propagated up
    }
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        vector<vector<int>> graph(n);
        for(auto it: edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        vector<int> ans;
        for(auto it: query){
            int start = it[0];
            int end = it[1];
            int target = it[2];
            int closestNode = dfs(graph, target, -1, start, end);

            if(closestNode == INT_MIN){
                continue;
            }
            ans.push_back(closestNode);
        }

        return ans;
    }
};