class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        //TC: O(NlogN)
        sort(points.begin(), points.end());
        
        int n = points.size(), dif = INT_MIN;
        //TC: O(N)
        for(int i = 1; i < n; i++){
            //TC: O(1)
            dif = max(dif, abs(points[i][0]-points[i-1][0]));
        }

        return dif;
    }
};