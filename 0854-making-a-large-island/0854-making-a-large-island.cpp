/*
    Input: grid = [[1,0],[0,1]]
    Output: 3  

    [1,0]
    [0,1]
      0 1 2 3
    0[0,0,0,1]
    1[1,0,0,1]
    2[1,1,0,1]
    3[0,0,1,0] 

    curRow * colSize + curCol
    1 * 4 + 3 = 7

    //first create the DSU class
    //there we will keep track of the row and columns that belongs to an island

    [0,0,0,0,0,0,0]
    [0,1,1,1,1,0,0]
    [0,1,0,0,1,0,0]
    [1,0,1,0,1,0,0]
    [0,1,0,0,1,0,0]
    [0,1,0,0,1,0,0]
    [0,1,1,1,1,0,0]

*/
//first create the DSU class
//there we will keep track of the row and columns that belongs to an island

class DSU{
public:
    vector<int> parent;
    vector<int> size;
    DSU(int n){
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUlParent(int node){
        if(parent[node] == node){
            return node;
        }
        //this is where the path compression happens
        return parent[node] = findUlParent(parent[node]);
    }
    //connect two cells to it's root parent
    void unionBySize(int node1, int node2){
        int parent1 = findUlParent(node1);
        int parent2 = findUlParent(node2);
        if(parent1 == parent2){
            return;
        }
        if(size[parent1] < size[parent2]){
            parent[parent1] = parent[parent2];
            size[parent2] += size[parent1];
        }
        else{
            parent[parent2] = parent[parent1];
            size[parent1] += size[parent2];
        }
        return;
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //Overall TC: O(4*N*M)
        //Overall SC: O(2*N*M+*)
        //SC: O(2*N*M)
        DSU dsu(n*m);
        int maxArea = 0;
        //SC: O(*)
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        //here we will connect the islands to its parent cell
        //basically mark the individual islands and with size
        //TC: O(N*M*4)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    for(auto it: dir){
                        int adjr = i+it[0];
                        int adjc = j+it[1];
                        //do boudary check
                        if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                            //then check if the adjacent cell = 1 then we join
                            if(grid[adjr][adjc] == 1){
                                int curCell = i * m + j;
                                int adjCell = adjr * m + adjc;
                                //O(1)
                                dsu.unionBySize(curCell, adjCell);
                                //maxArea = max(dsu.size[curCell], dsu.size[adjCell]);
                            }
                        }
                    }
                }
            }
        }

        //lastly here we will reiterate the grid
        //while doing so using dsu we will keep track of the new maxIsland
        //dsu.size[adjCell of 0th cell that has 1]
        //make it a 4 directional adjacent search from the 0th cell
        //TC: O(N*M*4)
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0){
                    int curArea = 0;
                    unordered_set<int> uniqueRoots;
                    for(auto it: dir){
                        int adjr = i+it[0];
                        int adjc = j+it[1];
                        //do boudary check
                        if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m){
                            //then check if the adjacent cell = 1 then we join
                            if(grid[adjr][adjc] == 1){
                                int adjCell = adjr * m + adjc;
                                //dsu.unionBySize(curCell, adjCell);
                                uniqueRoots.insert(dsu.findUlParent(adjCell));
                            }
                        }
                    }
                    for(auto it: uniqueRoots){
                        curArea += dsu.size[it];
                    }
                    maxArea = max(curArea+1, maxArea);
                }
            }
        }

        for(int curCell = 0; curCell < n*m; curCell++){
            maxArea = max(maxArea, dsu.size[curCell]);
        }

        return maxArea;
    }
};