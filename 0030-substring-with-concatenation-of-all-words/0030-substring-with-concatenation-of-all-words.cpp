class Solution {
private:
    unordered_map<string, int> wordCount;
    int n;
    int wordLength;
    int substringSize;
    int k;
    void slidingWindow(int left, string &s, vector<int> &answer) {
        unordered_map<string, int> wordsFound;
        int wordsUsed = 0;
        bool excessWord = false;
        for (int right = left; right <= n - wordLength; right += wordLength) {
            string sub = s.substr(right, wordLength);
            if (!wordCount.count(sub)) {
                // Mismatched word - reset the window
                wordsFound.clear();
                wordsUsed = 0;
                excessWord = false;
                left = right + wordLength;
            } else {
                // If we reached max window size or have an excess word
                while (right - left == substringSize || excessWord) {
                    string leftmostWord = s.substr(left, wordLength);
                    left += wordLength;
                    wordsFound[leftmostWord]--;
                    if (wordsFound[leftmostWord] >= wordCount[leftmostWord]) {
                        // This word was an excess word
                        excessWord = false;
                    } else {
                        // Otherwise we actually needed it
                        wordsUsed--;
                    }
                }
                // Keep track of how many times this word occurs in the window
                wordsFound[sub]++;
                if (wordsFound[sub] <= wordCount[sub]) {
                    wordsUsed++;
                } else {
                    // Found too many instances already
                    excessWord = true;
                }
                if (wordsUsed == k && !excessWord) {
                    // Found a valid substring
                    answer.push_back(left);
                }
            }
        }
    }

public:
    vector<int> findSubstring(string s, vector<string> &words) {
        n = s.length();
        k = words.size();
        wordLength = words[0].length();
        substringSize = wordLength * k;
        for (string &word : words) {
            wordCount[word]++;
        }
        vector<int> answer;
        for (int i = 0; i < wordLength; i++) {
            slidingWindow(i, s, answer);
        }
        return answer;
    }
};