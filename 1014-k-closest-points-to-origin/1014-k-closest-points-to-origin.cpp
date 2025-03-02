class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, vector<int>>> disVec;
        for(int i = 0; i < points.size(); i++){
            int dis = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            disVec.push_back({dis, points[i]});
        }

        sort(disVec.begin(), disVec.end());
        vector<vector<int>> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(disVec[i].second);
        }

        return ans;
    }
};