class Solution {
public:
    const int EMPTY = INT_MAX;
    const int GATE = 0;
    const vector<vector<int>> DIRECTIONS = {
        {1, 0},  // Down
        {-1, 0}, // Up
        {0, 1},  // Right
        {0, -1}  // Left
    };

    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size();
        if (m == 0) return;
        int n = rooms[0].size();
    
        queue<pair<int, int>> q;
    
        // Enqueue all gates
        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (rooms[row][col] == GATE) {
                    q.push({row, col});
                }
            }
        }
    
        // Perform BFS from each gate
        while (!q.empty()) {
            pair<int, int> point = q.front(); q.pop();
            int row = point.first;
            int col = point.second;
        
            for (const vector<int>& direction : DIRECTIONS) {
                int r = row + direction[0];
                int c = col + direction[1];
            
                // Check if the neighboring cell is within bounds and is empty
                if (r < 0 || c < 0 || r >= m || c >= n || rooms[r][c] != EMPTY) {
                    continue;
                }
            
                // Update the distance to the nearest gate
                rooms[r][c] = rooms[row][col] + 1;
            
                // Add the updated cell to the queue
                q.push({r, c});
            }
        }
    }
};