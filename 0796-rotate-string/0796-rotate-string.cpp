/*
    s = "abcde", goal = "cdeab"
     0 1 2 3 4
    "a b c d e"

    0+4/2 -> 2 

*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        int m = goal.length();

        if(n != m){
            return false;
        }

        string doubleString = s+s;
        if(doubleString.find(goal) < (int)doubleString.length()){
            return true;
        }

        return false;
    }
};