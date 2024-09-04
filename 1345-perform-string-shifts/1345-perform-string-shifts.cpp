class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {

        // Count the number of left shifts. A right shift is a negative left shift.
        int leftShifts = 0;
        for (const auto& move : shift) {
            if (move[0] == 1) {
                leftShifts -= move[1]; // Right shift
            } else {
                leftShifts += move[1]; // Left shift
            }
        }
        
        // Convert back to a positive, do left shifts, and return.
        int n = s.length();
        // cout << "leftShifts: " << leftShifts << endl;
        // cout << (leftShifts%n+n)%n << endl;
        leftShifts = (leftShifts % n + n) % n; // Equivalent to Math.floorMod in Java
        rotate(s.begin(), s.begin() + leftShifts, s.end());
        
        return s;
    }
};