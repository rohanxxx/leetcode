class Solution {
public:
    class DSU{
        public:
            vector<int> parent, size;
            DSU(int n){
                size.resize(n+1);
                parent.resize(n+1);
                for(int i = 0; i < n+1; i++){
                    parent[i] = i;
                    size[i] = 1;
                }
            }

            int findParent(int node){
                // this is our base case
                if(parent[node] == node) return parent[node];
                // this is where the path compression happens
                return parent[node] = findParent(parent[node]);
            }

            bool unionBySize(int node1, int node2){
                int n1parent = findParent(node1);
                int n2parent = findParent(node2);
                
                if(n1parent == n2parent) return true;
                if(size[n1parent] < size[n2parent]){
                    parent[n1parent] = parent[n2parent];
                    size[n2parent] += size[n1parent];
                }
                else {
                    parent[n2parent] = parent[n1parent];
                    size[n1parent] += size[n2parent];
                } 
                return false;
            }
    };

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        DSU dsu(n);
        for(auto it: edges){
            if(dsu.unionBySize(it[0], it[1])){
                return {it[0], it[1]};
            }
        }
        return {};
    }
};