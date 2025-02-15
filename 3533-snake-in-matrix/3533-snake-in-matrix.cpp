class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        unordered_map<string, vector<int>> mp;
        mp["LEFT"] = {0, -1};
        mp["RIGHT"] = {0, 1};
        mp["UP"] = {-1, 0};
        mp["DOWN"] = {1, 0};
        
        int xpos = 0, ypos = 0;
        for(int i = 0; i < commands.size(); i++){
            vector<int> v = mp[commands[i]];
            xpos += v[0]; ypos += v[1];
        }
        return ((xpos*n)+ypos);
    }
};