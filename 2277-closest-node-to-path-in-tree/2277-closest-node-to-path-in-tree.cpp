class Solution {
public:
    bool dfs(int node, int parent, int& target, vector<vector<int>>& graph, unordered_set<int>& myset){
        if(node == target){
            myset.insert(node);
            return true;
        }

        for(auto adjn: graph[node]){
            if(adjn == parent){
                continue;
            }
            if(dfs(adjn, node, target, graph, myset) == true){
                myset.insert(node);
                return true;
            }
        }
        return false;
    }

    int bfs(int node, vector<vector<int>>& graph, unordered_set<int>& myset){
        if(myset.find(node) != myset.end()){
            return node;
        }
        queue<vector<int>> q;
        q.push({node, -1});

        while(!q.empty()){
            auto it = q.front(); q.pop();
            int cur = it[0];
            int parent = it[1];

            for(auto adjn: graph[cur]){
                if(adjn == parent){
                    continue;
                }
                if(myset.find(adjn) != myset.end()){
                    return adjn;
                }
                q.push({adjn, cur});
            }
        }
        return -1;
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

            unordered_set<int> myset;

            dfs(start, -1, end, graph, myset);

            int closestNode = bfs(target, graph, myset);

            if(closestNode == -1){
                continue;
            }
            ans.push_back(closestNode);
        }

        return ans;
    }
};