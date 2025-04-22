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

            void unionBySize(int node1, int node2){
                int n1parent = findParent(node1);
                int n2parent = findParent(node2);
                
                if(n1parent == n2parent) return;
                if(size[n1parent] < size[n2parent]){
                    parent[n1parent] = parent[n2parent];
                    size[n2parent] += size[n1parent];
                }
                else {
                    parent[n2parent] = parent[n1parent];
                    size[n1parent] += size[n2parent];
                } 
            }
    };

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU disjointSet(n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isConnected[i][j] == 1) {
                    disjointSet.unionBySize(i+1, j+1);
                }
            }
        }

        int provinces = 0;
        for(int i = 1; i < n+1; i++){
            if(disjointSet.parent[i] == i){
                provinces++;
            }
        }
        return provinces;
    }
};