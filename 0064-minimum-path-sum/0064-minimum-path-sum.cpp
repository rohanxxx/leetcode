/*
    go: top left to right
    moves: down / right

    Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
    Output: 7   

    [1,3,1]
    [1,5,1]
    [4,2,1]


*/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 1 && grid[0].size() == 1) return grid[0][0];

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dist(grid.size(), vector<int>(grid[0].size(), INT_MAX));

        dist[0][0] = grid[0][0];
        pq.push({grid[0][0],{0,0}}); // path sum, row, col

        while(!pq.empty())
        {
            int d = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            if(row == n-1 && col == m-1) return dist[row][col];
            pq.pop();
            int rrow = row; 
            int rcol = col + 1; // for right column index
            if(rcol >= 0 && rcol < m && d + grid[rrow][rcol] < dist[rrow][rcol])
            {
                dist[rrow][rcol] = d + grid[rrow][rcol];
                pq.push({dist[rrow][rcol], {rrow, rcol}});
            }
            int drow = row + 1; // for down row index
            int dcol = col; 
            if(drow >= 0 && drow < n && d + grid[drow][dcol] < dist[drow][dcol])
            {
                dist[drow][dcol] = d + grid[drow][dcol];
                pq.push({dist[drow][dcol], {drow, dcol}});
            }
        }
        return 0;
    }
}; 