/*
    allowed to swap multiple times at specific indices in any order

    return the minimum hamming distance after performing specific action

    hamming distance is source[i] != target[i]

    source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
     0 1 2 3
    [2,1,4,3]
    [1,2,3,4]

    0 - 1 
    2 - 3

    3 1 2
    source = [1,2,3,4], target = [1,3,2,4]
                                 [1,2,3,4]
                                    0 1 2 3 4
    source = [5,1,2,4,3], target = [1,5,4,2,3], allowedSwaps = [[0,4],[4,2],[1,3],[1,4]]
     [0,4],[1,3],[1,4],[4,2]
     0 1 2 3 4
    [5,1,2,4,3]
    [1,5,4,2,3]

    0 - 4 - 1 - 3
         \
          2
    
              0 1 2 3
    source = [1,2,3,4]
    target = [1,3,2,4]

    0 1 2 3

    1 -> 2 different parent
    2 -> 1 different parent
*/
class Solution {
public:
    class DSU {
    public:
        vector<int> parent, size;

        DSU(int n){
            parent.resize(n);
            size.resize(n, 1);
            for(int i = 0; i < n; i++) parent[i] = i;
        }

        int findParent(int node){
            if(node != parent[node])
                parent[node] = findParent(parent[node]);
            return parent[node];
        }

        void unionBySize(int a, int b){
            int p1 = findParent(a);
            int p2 = findParent(b);
            if(p1 == p2) return;

            if(size[p1] >= size[p2]){
                parent[p2] = p1;
                size[p1] += size[p2];
            } else {
                parent[p1] = p2;
                size[p2] += size[p1];
            }
        }
    };

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        DSU dsu(n);

        for(auto &e : allowedSwaps){
            dsu.unionBySize(e[0], e[1]);
        }

        // 🔥 FIX: map value -> list of indices
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[target[i]].push_back(i);
        }

        int hammingDistance = 0;

        for(int i = 0; i < n; i++){
            int val = source[i];

            bool found = false;

            if(mp.count(val)){
                auto &vec = mp[val];

                // try to find a valid index in same component
                for(int j = 0; j < vec.size(); j++){
                    if(dsu.findParent(i) == dsu.findParent(vec[j])){
                        // use this index
                        vec.erase(vec.begin() + j);
                        found = true;
                        break;
                    }
                }
            }

            if(!found) {
                hammingDistance++;
            }
        }

        return hammingDistance;
    }
};