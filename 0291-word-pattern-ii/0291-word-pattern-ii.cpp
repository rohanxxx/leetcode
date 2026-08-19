class Solution {
public:
    bool backtrack(int i1, int i2, string& pattern, string& s,
                   unordered_map<char, string>& map,
                   unordered_map<string, char>& rmap) {
        if (i1 == (int)pattern.length() && i2 == (int)s.length()) {
            return true;
        }
        if (i1 == (int)pattern.length()) {
            return false;
        }
        if (i2 == (int)s.length()) {
            return false;
        }

        char key = pattern[i1];

        for (int j = i2; j < (int)s.size(); j++) {
            string curr = s.substr(i2, j - i2 + 1);

            bool keyExists = map.count(key) > 0;
            bool valExists = rmap.count(curr) > 0;

            bool keyFree = (!keyExists || map[key] == curr);
            bool valFree = (!valExists || rmap[curr] == key);

            if (keyFree && valFree) {
                bool setKey = !keyExists;  // only erase if we set it
                bool setVal = !valExists;

                map[key] = curr;
                rmap[curr] = key;

                if (backtrack(i1 + 1, j + 1, pattern, s, map, rmap)) {
                    return true;
                }

                if (setKey) { map.erase(key); }    // only undo what we set
                if (setVal) { rmap.erase(curr); }
            }
        }

        return false;
        // TC: O(n^m) where m = pattern length, n = s length
        // SC: O(m) recursion depth + map space
    }

    bool wordPatternMatch(string pattern, string s) {
        unordered_map<char, string> map;
        unordered_map<string, char> rmap;
        return backtrack(0, 0, pattern, s, map, rmap);
    }
};