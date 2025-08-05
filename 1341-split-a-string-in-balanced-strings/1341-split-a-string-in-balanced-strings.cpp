class Solution {
public:
    /*
        Input: s = "RLRRLLRLRL"
        Output: 4
        s = "RL RRLL RL RL"

        Input: s = "RL RRRLLRLL"
        Output: 2
    */
    int balancedStringSplit(string s) {
        unordered_map<char, int> map;

        bool valid = false;
        int count = 0, n = s.length();
        for(int i = 0; i < n; i++){
            char c = s[i];
            map[c]++;
            if(map['R'] == map['L']){ 
                if(i == n-1) valid = true;
                count++;
            }
        }
        if(valid) return count;
        return -1;
    }
};