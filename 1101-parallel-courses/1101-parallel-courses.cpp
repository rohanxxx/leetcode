class Solution {
public:
    int dfs(int node, vector<vector<int>>& graph, vector<int>& visited){
        if(visited[node] != 0) return visited[node];
        else {
            cout << "line 6 node: " << node << endl;
            visited[node] = -1;
        }

        int maxLength = 1;
        for(auto nextNode: graph[node]){
            int length = dfs(nextNode, graph, visited);
            if(length == -1) {
                cout << "line 14 node: " << node << endl;
                return -1;
            }
            maxLength = max(maxLength, length+1);
        }

        visited[node] = maxLength;
        return maxLength;
    }

    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> graph(n+1);
        //build the graph
        for(auto relation: relations){
            graph[relation[0]].push_back(relation[1]);
        }

        vector<int> visited(n+1);

        int maxLength = 1;
        for(int i = 1; i < n+1; i++){
            int length = dfs(i, graph, visited);
            if(length == -1) {
                cout << "line 37 node: " << i << endl;
                return -1;
            }
            maxLength = max(maxLength, length);
        }

        return maxLength;
    }
};