class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rottenQueue;
        int freshOranges = 0;
        int ROWS = grid.size(), COLS = grid[0].size();
        
        // Step 1: build the initial set of rotten oranges
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid[r][c] == 2)
                    rottenQueue.push(make_pair(r, c));
                else if (grid[r][c] == 1)
                    freshOranges++;
            }
        }
        
        // Mark the end of a round/level with a special pair (-1, -1)
        rottenQueue.push(make_pair(-1, -1));
        
        // Step 2: start the rotting process via BFS
        int minutesElapsed = -1;
        vector<vector<int>> directions = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };
        
        while (!rottenQueue.empty()) {
            pair<int, int> p = rottenQueue.front();
            rottenQueue.pop();
            int row = p.first;
            int col = p.second;
            
            if (row == -1) {
                // We finish one round of processing
                minutesElapsed++;
                // to avoid the endless loop, add a marker for the next round
                if (!rottenQueue.empty()) {
                    rottenQueue.push(make_pair(-1, -1));
                }
            } else {
                // this is a rotten orange
                // then it would contaminate its neighbors
                for (auto& d : directions) {
                    int neighborRow = row + d[0];
                    int neighborCol = col + d[1];
                    
                    if (neighborRow >= 0 && neighborRow < ROWS &&
                        neighborCol >= 0 && neighborCol < COLS) {
                        if (grid[neighborRow][neighborCol] == 1) {
                            // this orange would be contaminated
                            grid[neighborRow][neighborCol] = 2;
                            freshOranges--;
                            // this orange would then contaminate other oranges
                            rottenQueue.push(make_pair(neighborRow, neighborCol));
                        }
                    }
                }
            }
        }
        
        // return elapsed minutes if no fresh orange left
        if (freshOranges == 0) {
            return minutesElapsed;
        } else {
            return -1;
        }
    }
};
