class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n == 0) return 0;
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });

        int arrows = 1;
        int arrowPos = points[0][1];
        int xStart, xEnd;
        for(auto p: points){
            xStart = p[0]; xEnd = p[1];
            if(arrowPos < xStart){
                arrowPos = xEnd;
                arrows++;
            } 
        }
        return arrows;
    }
};