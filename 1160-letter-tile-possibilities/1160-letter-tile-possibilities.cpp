class Solution {
public:
    int numTilePossibilities(string tiles) {
        unordered_map<char, int> count;
        for (char c : tiles) {
            count[c]++;
        }

        return backtrack(count);
    }

private:
    int backtrack(unordered_map<char, int>& count) {
        int res = 0;
        for (auto& [c, freq] : count) {
            if (freq > 0) {
                count[c]--;
                res += 1; // count this combination
                res += backtrack(count); // continue exploring
                count[c]++; // backtrack
            }
        }
        return res;
    }
};