class Solution {
public:
    vector<vector<int>> paths;
    void dfs(vector<vector<int>>& graph, vector<int>& path, int index){
        if(index == graph.size()-1){
            paths.push_back(path);
        }
        for(int i = 0; i < graph[index].size(); i++){
            int node = graph[index][i];
            path.push_back(node);
            dfs(graph, path, node);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        path.push_back(0);
        dfs(graph, path, 0);
        return paths;
    }
};