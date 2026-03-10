/*
    logs = [
        [20190101,0,1],
        [20190104,3,4],
        [20190107,2,3],
        [20190211,1,5],
        [20190224,2,4],
        [20190301,0,3],
        [20190312,1,2],
        [20190322,4,5]]

        0 -> 1 -> 5  
        \
    2 -> 3 -> 4

    0->1->4
    \
    2->3->4


        
*/
class Solution {
public:
    class DSU {
        private:
            vector<int> parent, size;
        public:
            DSU(int n){
                this->parent.resize(n);
                this->size.resize(n);
                for(int i = 0; i < n; i++){
                    this->parent[i] = i;
                    this->size[i] = 1;
                }
            }


            int findUParent(int node){
                if(this->parent[node] == node) return this->parent[node];
                //path compression
                return this->parent[node] = findUParent(this->parent[node]);
            }

            bool unionBySize(int node1, int node2){
                int n1UParent = findUParent(node1);
                int n2UParent = findUParent(node2);

                //means already have the same parent
                //no need to merge
                if(n1UParent == n2UParent) return false;

                if(this->size[n1UParent] > this->size[n2UParent]){
                    this->parent[n2UParent] = this->parent[n1UParent];
                    this->size[n1UParent] += this->size[n2UParent];
                }
                else{
                    parent[n1UParent] = parent[n2UParent];
                    size[n2UParent] += size[n1UParent];
                }
                return true;
            }
    };
    int earliestAcq(vector<vector<int>>& logs, int n) {
        //TC: O(NlogN)
        sort(logs.begin(), logs.end());

        DSU dsu(n);
        int groupCount = n;
        for(auto it: logs){
            int t = it[0];
            int u = it[1];
            int v = it[2];
            if(dsu.unionBySize(u,v) == true){
                groupCount--;
            }
            if(groupCount == 1){
                return t;
            }
        }

        return -1;
    }
};