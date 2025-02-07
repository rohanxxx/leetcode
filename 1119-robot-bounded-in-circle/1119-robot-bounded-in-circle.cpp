class Solution {
public:
    bool isRobotBounded(string instructions) {
        // north = 0, east = 1, south = 2, west = 3
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1, 0}};
        int index = 0, x = 0, y = 0;
        for(char c: instructions){
            if(c == 'L'){
                index = (index+3) % 4;
                continue;
            }
            if(c == 'R'){
                index = (index+1) % 4;
                continue;
            }

            x += dir[index][0];
            y += dir[index][1];
        }
        return (x == 0 && y == 0) || (index != 0);
    }
};