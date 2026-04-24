/*
    L_RL__R

    -3

    |0--3|
    count return dashes + max(countR, countL);
*/
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int dashCount, lCount, rCount;
        dashCount = lCount = rCount = 0;
        for(auto move: moves){
            if(move == 'L') lCount++;
            if(move == 'R') rCount++;
            if(move == '_') dashCount++;
        }

        return dashCount+ (int)max(lCount, rCount) - (int)min(lCount, rCount);
    }
};