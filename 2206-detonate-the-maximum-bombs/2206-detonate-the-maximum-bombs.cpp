class Solution {
public:
    int dfs(int i, unordered_map<int, vector<int>>& graph){
        unordered_set<int> visited;
        stack<int> stack;
        stack.push(i);
        visited.insert(i);
        
        while(!stack.empty()){
            int cur = stack.top();
            stack.pop();
            for(int n: graph[cur]){
                if(visited.find(n) == visited.end()){
                    visited.insert(n);
                    stack.push(n);
                }
            }
        }

        return visited.size();
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        unordered_map<int, vector<int>> graph;
        
        // builds the graph
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(j == i) continue;
                int xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];
                int xj = bombs[j][0], yj = bombs[j][1];

                if((long long) ri*ri >= (long long) (xi-xj) * (xi-xj) + (long long)(yi-yj)*(yi-yj)){
                    graph[i].push_back(j);
                }

            }
        }

        int answer = 0;
        for(int i = 0; i < n; i++){
            answer = max(answer, dfs(i, graph));
        }

        return answer;
    }
};