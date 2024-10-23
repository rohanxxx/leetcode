class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int, vector<int>> graph;
        int n = bombs.size();
        
        // Build the graph
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                int xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];
                int xj = bombs[j][0], yj = bombs[j][1];

                // Create a path from node i to node j, if bomb i detonates bomb j.
                if ((long long)ri * ri >= (long long)(xi - xj) * (xi - xj) + (long long)(yi - yj) * (yi - yj)) {
                    graph[i].push_back(j);
                }
            }
        }
        
        int answer = 0;
        for (int i = 0; i < n; i++) {
            int x = dfs(i, graph);
            answer = max(answer, x);
        }
        
        return answer;
    }
    
private:
    int dfs(int i, unordered_map<int, vector<int>>& graph) {
        stack<int> stk;
        unordered_set<int> visited;
        stk.push(i);
        visited.insert(i);
        while (!stk.empty()) {
            int cur = stk.top();
            stk.pop();
            for (int neib : graph[cur]) {
                if (visited.find(neib) == visited.end()) {
                    visited.insert(neib);
                    stk.push(neib);
                }
            }
        }
        return visited.size();
    }
};