class DSU {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DSU(int size){
        parent.resize(size);
        rank.resize(size, 0);
        for(int i = 0; i < size; i++){
            parent[i] = i;
        }
    }

    int find(int x){
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unionSets(int x, int y){
        int xr = find(x);
        int yr = find(y);

        if(xr == yr){
            return false;
        }
        else if (rank[xr] < rank[yr]){
            parent[xr] = yr;
        }
        else if (rank[xr] > rank[yr]){
            parent[yr] = xr;
        }
        else{
            parent[yr] = xr;
            rank[xr]++;
        }

        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU dsu(1000+1);
        for(const auto& edge: edges){
            if(!dsu.unionSets(edge[0], edge[1])){
                return edge;
            }
        }

        return {};
    }
};