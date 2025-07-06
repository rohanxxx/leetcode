class Solution {
public:
    void dfs(int node, vector<int>& component, vector<int>& visited, vector<vector<int>>& graph){
        //mark visited
        visited[node] = 1;
        component.push_back(node);
        //goes through all of it's edges
        for(int curNode: graph[node]){
            if(visited[curNode] == 0){
                dfs(curNode, component, visited, graph);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<int> visited(n,0), counter(n,0);
        vector<vector<int>> graph(n);
        //O(N+E)
        for(auto& it: edges){
            int u = it[0];
            int v = it[1];
            //generates the graph
            graph[u].push_back(v);
            graph[v].push_back(u);
            //gets the counter
            counter[u]++;
            counter[v]++;
        }

        int fullComponent = 0;
        for(int i = 0; i < n; i++){
            //if visited then skip rest of it
            if(visited[i] == 1) continue;
            
            vector<int> component;
            dfs(i, component, visited, graph);

            //flags valid component
            bool check = true;
            //goes through all the nodes of a single component
            for(auto& it: component){
                if(counter[it] != component.size()-1) {
                    check = false;
                    break;
                }
            }

            //if a component is full then increment the count
            if(check == true) fullComponent++;
        }

        return fullComponent;
    }
};