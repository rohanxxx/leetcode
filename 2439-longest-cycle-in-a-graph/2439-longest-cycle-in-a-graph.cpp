class Solution {
public:
    int ans = -1;
    void dfs(int curNode, vector<bool>& visited, unordered_map<int, int>& distMap, vector<int>& edges){
        visited[curNode] = true;
        int adjNode = edges[curNode];
        if(adjNode != -1 && visited[adjNode] == false){
            //visited[adjNode] = true;
            distMap[adjNode] = distMap[curNode]+1;
            dfs(adjNode, visited, distMap, edges);
        }
        else if(adjNode != -1 && distMap[adjNode] > 0){
            ans = max(ans, distMap[curNode]-distMap[adjNode]+1);
        }
    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> visited (n, false);
        for(int i = 0; i < n; i++){
            if(visited[i] == false){
                unordered_map<int, int> distMap;
                distMap[i] = 1;
                dfs(i, visited, distMap, edges);
            }
        }
        return ans;
    }
};