class DetectSquares {
private:
    unordered_map<int, unordered_map<int, int>> MAP;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        MAP[x][y]++;
    }
    
    int count(vector<int> point) {
        int ans = 0;
        int x1 = point[0];
        int y1 = point[1];

        for(auto &[y2, _]: MAP[x1]){
            if(y1 == y2) continue;
            int d = abs(y2-y1);
            
            ans += MAP[x1][y2] * 
                    (MAP[x1 - d][y2] * MAP[x1 - d][y1] 
                        + MAP[x1 + d][y2] * MAP[x1 + d][y1]);
        }

        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */