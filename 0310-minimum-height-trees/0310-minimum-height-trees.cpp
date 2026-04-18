class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1) return {0};

        vector<int> indegree(n);
        vector<vector<int>> graph(n);

        for(auto& it: edges){
            int u = it[0], v = it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }

        queue<pair<int,int>> q;

        // push initial leaves
        for(int i = 0; i < n; i++){
            if(--indegree[i] == 0){
                q.push({-1, i});
            }
        }

        int remainingNodes = n;

        while(remainingNodes > 2){
            int size = q.size();
            remainingNodes -= size;

            for(int i = 0; i < size; i++){
                int parent = q.front().first;
                int node = q.front().second;
                q.pop();

                for(auto adjn: graph[node]){
                    if(adjn != parent && --indegree[adjn] == 0){
                        q.push({node, adjn});
                    }
                }
            }
        }

        vector<int> centroidNodes;
        while(!q.empty()){
            centroidNodes.push_back(q.front().second);
            q.pop();
        }

        return centroidNodes;
    }
};