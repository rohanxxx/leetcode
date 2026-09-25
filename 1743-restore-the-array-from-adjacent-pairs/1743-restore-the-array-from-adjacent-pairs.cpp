class Solution {
public:
    void dfs(int node, int parent, unordered_map <int, vector<int>>& graph, vector<int>& ans){
        ans.push_back(node);
        for(auto adjNode: graph[node]){
            if(adjNode == parent){
                continue;
            }
            dfs(adjNode, node, graph, ans);
        }
        return;
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> graph;
        for(auto it: adjacentPairs){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }

        int root = 0;
        for(auto it: graph){
            if(it.second.size() == 1){
                root = it.first;
                break;
            }
        }
        
        vector<int> ans;
        
        dfs(root, INT_MAX, graph, ans);
        
        return ans;
    }
};