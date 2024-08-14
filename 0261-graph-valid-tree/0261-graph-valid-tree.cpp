class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> tree(n);
        //bulding the graph
        for(auto &edge: edges){
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }

        unordered_map<int, int> parent;
        parent[0] = -1;

        queue<int> stack;
        stack.push(0);

        while(!stack.empty()){
            int node = stack.front(); stack.pop();
            for(auto nextNode: tree[node]){
                //detects the parentNode
                if(parent[node] == nextNode) continue;
                //detects the cycle
                if(parent.find(nextNode) != parent.end()) return false;

                //dfs
                stack.push(nextNode);
                parent[nextNode] = node;
            }
        }

        return parent.size() == n;
    }
};