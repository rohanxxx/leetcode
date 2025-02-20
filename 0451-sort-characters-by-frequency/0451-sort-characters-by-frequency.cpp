class Solution {
public:
    string frequencySort(string s) {
        if (s.empty()) return s;
        // Count occurrences of each character
        unordered_map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }
        // Find the maximum frequency
        int maximumFrequency = 0;
        for (const auto& pair : counts) {
            maximumFrequency = max(maximumFrequency, pair.second);
        }
        // Create buckets for bucket sort
        vector<vector<char>> buckets(maximumFrequency + 1);
        for (const auto& pair : counts) {
            // cout << "pair.second: " << pair.second << ", pair.first: " << pair.first << endl;
            buckets[pair.second].push_back(pair.first);
        }
        // Build the sorted string
        string result;
        for (int i = maximumFrequency; i > 0; i--) {
            for (char c : buckets[i]) {
                // cout << "i: " << i << ", c: " << c << endl;
                result.append(i, c);  // Append character `i` times
            }
        }
        return result;
    }
};