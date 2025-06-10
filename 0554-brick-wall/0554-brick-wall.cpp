/*
 [1,2,2,1] 1   3   5 6
 [3,1,2]       3 4   6
 [1,3,2].  1     4   6
 [2,4].      2       6
 [3,1,2].      3 4.  6
 [1,3,1,1] 1     4.5 6

 1 2 3 4 5 6

 1,2 -> 6-3 = 3
 2,3 -> 6-5 = 1
 3,4 -> 6-3 = 4
 4,5 -> 6-4 = 2

 [1]
 [1]
 [1]
*/

/*
 [1,2,2,1] 1   3   5 6
 [3,1,2]       3 4   6
 [1,3,2].  1     4   6
 [2,4].      2       6
 [3,1,2].      3 4.  6
 [1,3,1,1] 1     4.5 6

 1 2 3 4 5 6

 1,2 -> 6-3 = 3
 2,3 -> 6-5 = 1
 3,4 -> 6-3 = 4
 4,5 -> 6-4 = 2

 [1]
 [1]
 [1]
*/

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        unordered_map<int, int> freq;

        for (int i = 0; i < n; i++) {
            long long curRowWidth = 0;
            for (int j = 0; j < wall[i].size() - 1; j++) {
                curRowWidth += wall[i][j];
                freq[curRowWidth]++;
            }
        }

        int maxGaps = 0;
        for (auto& [pos, count] : freq) {
            maxGaps = max(maxGaps, count);
        }

        return n - maxGaps;
    }
};