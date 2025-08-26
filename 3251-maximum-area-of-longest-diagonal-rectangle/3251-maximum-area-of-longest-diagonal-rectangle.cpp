/*
    [[2,6],[5,1],[3,10],[8,4]]
      12.   5.     30.    32
      (40). (26).  (109) (80)

    asking me to return the area of the rectangle having the longest diagonal
*/
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxDiagonal = 0;
        
        int ans = 0;
        for(auto& it: dimensions){
            int curArea = it[0] * it[1];
            double diagonal = (double)sqrt(pow(it[0], 2) + pow(it[1],2));
            if(diagonal >= maxDiagonal){
                if(diagonal == maxDiagonal) ans = max(curArea, ans);
                else ans = curArea;
                maxDiagonal = diagonal;
            }
        }

        return ans;
    }
};