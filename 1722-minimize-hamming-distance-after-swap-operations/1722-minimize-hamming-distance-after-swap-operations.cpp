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
    private:
        vector<int> parent, size;
    public:
        DSU(int n){
            this->parent.resize(n);
            this->size.resize(n, 1);
            for(int i = 0; i < n; i++){
                this->parent[i] = i;
            }
        }

        int findParent(int node){
            if(node != this->parent[node]){
                this->parent[node] = findParent(this->parent[node]);
            }
            return this->parent[node];
        }

        void unionBySize(int node1, int node2){
            int p1 = findParent(node1);
            int p2 = findParent(node2);

            if(p1 == p2) return;

            if(this->size[p1] >= this->size[p2]){
                this->parent[p2] = p1;
                this->size[p1] += this->size[p2];   // ✅ fixed
            }
            else{
                this->parent[p1] = p2;
                this->size[p2] += this->size[p1];
            }
        }
    };

    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = target.size();

        DSU dsu(n);

        // connect the edges
        for(auto swap: allowedSwaps){
            dsu.unionBySize(swap[0], swap[1]);
        }

        // 🔥 parent -> (value -> count)
        unordered_map<int, unordered_map<int, int>> map;

        for(int i = 0; i < n; i++){
            int parent = dsu.findParent(i);
            map[parent][target[i]]++;
        }

        int hammingDistance = 0;

        for(int i = 0; i < n; i++){
            int parent = dsu.findParent(i);

            if(map[parent][source[i]] > 0){
                map[parent][source[i]]--;   // consume match
            }
            else{
                hammingDistance++;
            }
        }

        return hammingDistance;
    }
};