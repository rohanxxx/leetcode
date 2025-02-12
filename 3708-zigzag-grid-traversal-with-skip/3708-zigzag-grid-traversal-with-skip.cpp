class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        int r = grid.size(), col = grid[0].size();
        
        vector<int> ans;
        bool prevTake = false;
        for(int i = 0; i < r; i += 2){
            for(int j = 0; j < col; j++){
                if(!prevTake){
                    ans.push_back(grid[i][j]);
                    prevTake = true;
                    continue;
                }
                prevTake = false;
            }

            if(i+1 < r){
                for(int j = col-1; j >= 0; j--){
                    if(!prevTake){
                        ans.push_back(grid[i+1][j]);
                        prevTake = true;
                        continue;
                    }
                    prevTake = false;
                }
            }

        }
        return ans;
    }
};