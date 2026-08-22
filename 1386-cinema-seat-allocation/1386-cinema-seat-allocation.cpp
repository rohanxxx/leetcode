class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_map<int, int>> map;
        for(auto it: reservedSeats){
            int r = it[0];
            int c = it[1];
            map[r][c] = 1;
        }

        int count = 0;

        // only iterate rows that have reservations
        for(auto& [r, seats] : map){
            bool left  = !seats[2] && !seats[3] && !seats[4] && !seats[5];
            bool mid   = !seats[4] && !seats[5] && !seats[6] && !seats[7];
            bool right = !seats[6] && !seats[7] && !seats[8] && !seats[9];

            if(left && right){
                count += 2;
            } else if(left || mid || right){
                count += 1;
            }
        }

        // every row with no reservations fits exactly 2 families
        int emptyRows = n - (int)map.size();
        count += emptyRows * 2;

        return count;
        // TC: O(R) where R = number of reserved seats
        // SC: O(R)
    }
};