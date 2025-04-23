class Solution {
public:
    class DSU{
    public:
        vector<int> parent;
        vector<int> size;

        DSU(int n){
            parent.resize(n+1);
            size.resize(n+1);
            for(int i = 0; i < n+1; i++){
                parent[i] = i; size[i] = 1;
            }
        }

        int findParent(int node){
            if(node == parent[node]) return node;
            return parent[node] = findParent(parent[node]);
        }

        void unionBySize(int node1, int node2){
            int p1 = findParent(node1);
            int p2 = findParent(node2);
            if(p1 == p2) return;
            if(size[p1] < size[p2]){
                parent[p1] = parent[p2];
                size[p2] += size[p1];
            }
            else{
                parent[p2] = parent[p1];
                size[p1] = size[p2];
            }
        }
    };

    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        DSU dsu(m*n);
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int count = 0;
        vector<int> ans;
        vector<vector<int>> dir = {{1,0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto node: positions){
            int r = node[0];
            int c = node[1];
            if(visited[r][c] == true){
                ans.push_back(count);
                continue;
            }
            visited[r][c] = true;
            count++;

            for(auto d: dir){
                int adjr = r+d[0];
                int adjc = c+d[1];
                if(adjr >= 0 && adjr < m && adjc >= 0 && adjc < n){
                    if(visited[adjr][adjc] == true){
                        int curNodeNo = r * n + c;
                        int adjNodeNo = adjr * n + adjc;
                        if(dsu.findParent(curNodeNo) != dsu.findParent(adjNodeNo)){
                            count--;
                            dsu.unionBySize(curNodeNo, adjNodeNo);
                        }
                    }
                }
            }

            ans.push_back(count);
        }
        return ans;
    }
};