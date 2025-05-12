/*
    Input: words = ["dog","cat","dad","good"],              
    letters = ["a","a","c","d","d","d","g","o","o"], 
    score = [1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0]
             a b c d e f g h i j k l m n o   
    Output: 23
    dog = 5 + 2 + 3 = 10, 
    cat = 9 + 1 + 0 = 10,
    dad = 5 + 1 + 5 = 11,
    good = 3 + 2 + 2 + 5 = 12
*/
class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters,
                      vector<int>& score) {
        int W = words.size();
        maxScore = 0;
        freq = vector<int>(26, 0);
        vector<int> subsetLetters = vector<int>(26, 0);
        // Count how many times each letter occurs
        for (char c : letters) {
            freq[c - 'a']++;
        }
        check(W - 1, words, score, subsetLetters, 0);
        return maxScore;
    }

private:
    int maxScore;
    vector<int> freq;

    // Check if adding this word exceeds the frequency of any letter
    bool isValidWord(vector<int>& subsetLetters) {
        for (int c = 0; c < 26; c++) {
            if (freq[c] < subsetLetters[c]) {
                return false;
            }
        }
        return true;
    }

    void check(int w, vector<string>& words, vector<int>& score,
               vector<int>& subsetLetters, int totalScore) {
        if (w == -1) {
            // If all words have been iterated, check the score of this subset
            maxScore = max(maxScore, totalScore);
            return;
        }
        // Not adding words[w] to the current subset
        check(w - 1, words, score, subsetLetters, totalScore);
        // Adding words[w] to the current subset
        int L = words[w].length();
        for (int i = 0; i < L; i++) {
            int c = words[w][i] - 'a';
            subsetLetters[c]++;
            totalScore += score[c];
        }

        if (isValidWord(subsetLetters)) {
            // Consider the next word if this subset is still valid
            check(w - 1, words, score, subsetLetters, totalScore);
        }
        // Rollback effects of this word
        for (int i = 0; i < L; i++) {
            int c = words[w][i] - 'a';
            subsetLetters[c]--;
            totalScore -= score[c];
        }
    }
};