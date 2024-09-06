class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> map;

        for (char c : s) {
            map[c]++;
        }

        int count = 0;
        for (auto it : map) {
            count += it.second % 2;
        }

        return count <= 1;
    }
};