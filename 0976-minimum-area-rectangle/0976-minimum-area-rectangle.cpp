class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_map<int, unordered_set<int>> hashmap;
        for(auto& point: points){
            hashmap[point[0]].insert(point[1]);
        }
        int minArea = INT_MAX;
        for(int i = 0; i < points.size(); i++){
            for(int j = i+1; j < points.size(); j++){
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                if(x1 != x2 && y1 != y2){
                    if( hashmap[x1].find(y2) != hashmap[x1].end()
                                        &&
                        hashmap[x2].find(y1) != hashmap[x2].end()){
                            int w = abs(y2-y1);
                            int l = abs(x2-x1);
                            int area = w * l;
                            minArea = min(area, minArea);
                        }
                }
            }
        }
        if(minArea == INT_MAX) return 0;
        
        return minArea;
    }
};