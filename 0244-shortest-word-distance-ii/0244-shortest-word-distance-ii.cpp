/*
          0         1           2       3           4
    [[["practice", "makes", "perfect", "coding", "makes"]], ["coding", "practice"], ["makes", "coding"]]
*/
class WordDistance {
private:
    unordered_map<string, vector<int>> locations;

public:
    WordDistance(vector<string>& words) {
        // Prepare a mapping from a word to all its locations (indices).
        for (int i = 0; i < words.size(); ++i) {
            locations[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int> loc1 = locations[word1];
        vector<int> loc2 = locations[word2];

        int l1 = 0, l2 = 0;
        int minDiff = INT_MAX;

        // The indices are in SORTED order by default
        while (l1 < loc1.size() && l2 < loc2.size()) {
            minDiff = min(minDiff, abs(loc1[l1] - loc2[l2]));
            if (loc1[l1] < loc2[l2]) {
                ++l1;
            } else {
                ++l2;
            }
        }

        return minDiff;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */