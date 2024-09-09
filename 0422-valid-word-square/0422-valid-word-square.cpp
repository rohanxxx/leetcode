class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int cols = 0;
        int rows = words.size();
        vector<string> columnWords;
        
        for (auto& word : words) {
            cols = max(cols, (int)word.size());
        }

        if (cols != words[0].size() || rows != cols) {
            return false;
        }

        for (int col = 0; col < cols; ++col) {
            string newWord;
            for (int row = 0; row < rows; ++row) {
                if (col < words[row].size()) {
                    newWord += words[row][col];
                }
            }
            columnWords.push_back(newWord);
        }
        return words == columnWords;
    }
};