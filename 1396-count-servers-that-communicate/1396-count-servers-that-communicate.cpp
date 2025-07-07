class DSU {
public:
    vector<int> parent;
    vector<int> size;
    
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUlParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUlParent(parent[node]);
    }

    void unionBySize(int node1, int node2){
        int parentOfNode1 = findUlParent(node1);
        int parentOfNode2 = findUlParent(node2);
        if(parentOfNode1 == parentOfNode2) return;
        if(size[parentOfNode1] < size[parentOfNode2]){
            parent[parentOfNode1] = parent[parentOfNode2];
            size[parentOfNode2] += size[parentOfNode1];
        }
        else{
            parent[parentOfNode2] = parent[parentOfNode1];
            size[parentOfNode1] += size[parentOfNode2];
        }
    }
};
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        DSU dsu(n+m);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    dsu.unionBySize(i, j+n+1);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int parent = dsu.findUlParent(i); // could also use j + n + 1
                    if (dsu.size[parent] > 2) count++;
                }
            }
        }

        return count;
    }
};