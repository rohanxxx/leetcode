class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        
        if(n == 1) return 1;
        
        int result = 0;
        for(int i = 0; i < points.size(); i++){
            unordered_map<double, int> mp;
            for(int j = 0; j < n; j++){
                if(j != i){
                    result = max(result, ++mp[atan2(points[j][1]-points[i][1], points[j][0]-points[i][0])]+1);
                }
            }
        }

        return result;

    }
};