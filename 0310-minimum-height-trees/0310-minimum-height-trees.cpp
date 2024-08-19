class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 0) return {};
        if(n == 1) return {0};

        vector<int> res;
        vector<int> degree(n, 0);
        vector<vector<int>> graph(n); 

        for(auto edge: edges){
            degree[edge[0]]++;
            degree[edge[1]]++;
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        queue<int> q; 
        for(int i = 0; i < n; i++){
            if(degree[i] == 1) q.push(i);
        }

        while(n > 2){
            int size = q.size();
            n -= size;

            while(size > 0){
                int node = q.front();
                q.pop();
                for(auto nextNode: graph[node]){
                    degree[nextNode]--;
                    if(degree[nextNode] == 1){
                        q.push(nextNode);
                    }
                }
                size--;
            }


        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            res.push_back(node);
        }

        return res;
    }
};