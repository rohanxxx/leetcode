class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> ladderAllocations; // Min-heap
        for (int i = 0; i < heights.size() - 1; i++) {
            int climb = heights[i + 1] - heights[i];
            
            // If this is actually a "jump down", skip it.
            if (climb <= 0) {
                continue;
            }
            
            // Otherwise, allocate a ladder for this climb.
            ladderAllocations.push(climb);
            
            // If we haven't exceeded the number of ladders, continue.
            if (ladderAllocations.size() <= ladders) {
                continue;
            }
            
            // Otherwise, replace a ladder use with bricks.
            bricks -= ladderAllocations.top();
            ladderAllocations.pop();
            
            // If bricks go negative, return the last reachable building.
            if (bricks < 0) {
                return i;
            }
        }
        
        // If we reach here, we were able to cover all climbs.
        return heights.size() - 1;
    }
};