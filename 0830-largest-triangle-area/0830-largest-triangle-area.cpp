class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        const int n = (int)points.size();
        double best = 0.0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    // Coordinates
                    double x1 = points[i][0], y1 = points[i][1];
                    double x2 = points[j][0], y2 = points[j][1];
                    double x3 = points[k][0], y3 = points[k][1];

                    // Area = | (x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1) | / 2
                    double cross = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);
                    double area = fabs(cross) / 2.0;

                    best = max(best, area);
                }
            }
        }
        return best;
    }
};