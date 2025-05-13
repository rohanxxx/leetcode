class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> rowMap;
        for(auto &point: points){
            int x = point[0];
            int y = point[1];
            rowMap[x].insert(y);
        }

        int minArea = INT_MAX;
        int n = points.size();
        for(int i = 0; i < n; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];
            for(int j = i+1; j < n; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];
                if(x1 != x2 && y1 != y2){
                    if(rowMap[x1].find(y2) != rowMap[x1].end()
                        &&
                        rowMap[x2].find(y1) != rowMap[x2].end()){
                            int height = abs(y2-y1);
                            int width = abs(x2-x1);
                            minArea = min(minArea, height*width);
                        }
                }
            }
        }

        if(minArea == INT_MAX){
            return 0;
        }
        return minArea;
    }
};