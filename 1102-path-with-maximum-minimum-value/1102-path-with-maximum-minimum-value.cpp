/*
    (0,0) -> (m-1, n-1)
    moves -> 4 cardinal direction
    The score of path is the minimum value in that path

    [5,4,5]
    [1,2,6]
    [7,4,6]

    5x 1 4x 5x 2 6x 2 6(m-1, n-1)

    [2,2,1,2,2,2]
    [1,2,2,2,1,2]

    2x 1 2x 1 2x 2x 2 1

    maxHeap{val, minValOfMax, r,c}


    [3,4,6,3,4]
    [0,2,1,1,7]
    [8,8,3,2,7]
    [3,2,4,9,8]
    [4,1,2,0,0]
    [4,6,5,4,3]

    3x 0 4x 2 6x 1 3x 1 4x 7x 7x 2 8x 0 9x 4x 2 3x 8x 8x 3
*/
class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        //SC: O(M*N)
        vector<vector<int>> minSoFar(m, vector<int>(n,-1));

        priority_queue<vector<int>> maxHeap;
        maxHeap.push({grid[0][0], grid[0][0], 0, 0});
        minSoFar[0][0] = grid[0][0];

        vector<pair<int, int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};

        //TC: O(M*NLog(M*N))
        //SC: O(M*N)
        while(!maxHeap.empty()){
            auto it = maxHeap.top(); maxHeap.pop();
            int minNode = it[0];
            int node = it[1];
            int r = it[2];
            int c = it[3];

            if(r == m-1 && c == n-1){
                return minNode;
            }
            //check neighbors
            for(auto neighbor: dir){
                int adjr = neighbor.first+r;
                int adjc = neighbor.second+c;
                //out of bounds
                if(adjr < 0 || adjc < 0 || adjr >= m || adjc >= n){
                    continue;
                }
                int adjNode = grid[adjr][adjc];
                int updatedMin = (int)min(adjNode, minNode);
                //if visited then skip
                if(updatedMin <= minSoFar[adjr][adjc]){
                    continue;
                }

                //if not visited
                maxHeap.push({updatedMin, adjNode, adjr, adjc});
                minSoFar[adjr][adjc] = updatedMin;
            }
        }

        return -1;
    }
};