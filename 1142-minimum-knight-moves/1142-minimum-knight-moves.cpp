#include <vector>
#include <deque>
#include <array>
using namespace std;

class Solution {
public:
    int minKnightMoves(int x, int y) {
        // the offsets in the eight directions
        vector<array<int, 2>> offsets = {
            {1, 2}, {2, 1}, {2, -1}, {1, -2},
            {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}
        };
        
        // create a bitmap that is sufficient to cover all the possible inputs
        vector<vector<bool>> visited(607, vector<bool>(607, false));
        
        deque<array<int, 2>> queue;
        queue.push_back({0, 0});
        int steps = 0;
        
        while (!queue.empty()) {
            int currLevelSize = queue.size();
            // iterate through the current level
            for (int i = 0; i < currLevelSize; ++i) {
                array<int, 2> curr = queue.front();
                queue.pop_front();
                if (curr[0] == x && curr[1] == y) {
                    return steps;
                }
                
                for (const auto& offset : offsets) {
                    array<int, 2> next = {curr[0] + offset[0], curr[1] + offset[1]};
                    // align the coordinate to the bitmap
                    if (!visited[next[0] + 302][next[1] + 302]) {
                        visited[next[0] + 302][next[1] + 302] = true;
                        queue.push_back(next);
                    }
                }
            }
            ++steps;
        }
        // move on to the next level
        return steps;
    }
};
