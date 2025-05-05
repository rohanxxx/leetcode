/*
    [1,1,0,0,0]
    [1,0,0,0,0]
    [0,0,0,0,1]
    [0,0,0,1,1] expected -> 1

    1 1
      1


*/

class Solution {
public:
    int numDistinctIslands2(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        int m = grid.size(), n = grid[0].size();
        set<vector<pair<int, int>>> shapes;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    vector<pair<int, int>> shape;
                    distinct(grid, i, j, shape);
                    shapes.insert(normalize(shape));
                }
            }
        }
        return shapes.size();
    }
private:
    void distinct(vector<vector<int>>& grid, int i, int j, vector<pair<int, int>>& shape) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i == m || j < 0 || j == n || !grid[i][j]) {
            return;
        }
        grid[i][j] = 0;
        shape.push_back({i, j});
        distinct(grid, i - 1, j, shape);
        distinct(grid, i + 1, j, shape);
        distinct(grid, i, j - 1, shape);
        distinct(grid, i, j + 1, shape);
    }
    
    vector<pair<int, int>> normalize(vector<pair<int, int>>& shape) {
        int n = shape.size();
        vector<vector<pair<int, int>>> shapes(8);
        for (auto point : shape) {
            int x = point.first, y = point.second;
            shapes[0].push_back({x, y});
            shapes[1].push_back({x, -y});
            shapes[2].push_back({-x, y});
            shapes[3].push_back({-x, -y});
            shapes[4].push_back({y, x});
            shapes[5].push_back({y, -x});
            shapes[6].push_back({-y, x});
            shapes[7].push_back({-y, -x});
        }
        for (auto& shape_ : shapes) {
            sort(shape_.begin(), shape_.end());
            for (int i = n - 1; i >= 0; i--) {
                shape_[i].first -= shape_[0].first;
                shape_[i].second -= shape_[0].second;
            }
        }
        sort(shapes.begin(), shapes.end());
        return shapes[0];
    }
};