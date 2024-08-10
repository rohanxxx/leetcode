class Solution {
public:
    vector<string> getWords(int i, vector<string>& words, int maxWidth){
        vector<string> currentLine;
        int currentLength = 0;
        while(i < words.size() && currentLength+words[i].size() <= maxWidth){
            currentLine.push_back(words[i]);
            currentLength += words[i].length()+1; i++;
        }
        return currentLine;
    }

    string join(vector<string>& line, const string& delimeter) {
        if (line.empty()) {
            return "";
        }
        string res(line[0]);
        for (int i = 1; i < line.size(); i++) {
            res += delimeter + line[i];
        }
        return res;
    }

    string createLine(vector<string>& line, int i, vector<string>& words, int maxWidth) {
        int baseLength = -1;
        for (const string& word : line) {
            baseLength += word.size() + 1;
            // cout << "word: " << word << endl;
            // cout << "word.size(): " << word.size() << endl;
        }
        cout << "\nbaseLength: " << baseLength << endl;
        int extraSpaces = maxWidth - baseLength;
        cout << "extraSpaces: " << extraSpaces << endl;

        if (line.size() == 1 || i == words.size()) {
            string res = join(line, " ");
            res += string(extraSpaces, ' ');
            return res;
        }
        int wordCount = line.size() - 1;
        cout << "wordCount: " << wordCount << endl;
        int spacesPerWord = extraSpaces / wordCount;
        cout << "spacesPerWord: " << spacesPerWord << endl;
        int needsExtraSpace = extraSpaces % wordCount;
        cout << "needsExtraSpace: " << needsExtraSpace << endl;
        for (int j = 0; j < needsExtraSpace; j++) {
            cout << "line: 47" << endl; 
            cout << "line[" << j << "]: " << line[j] << endl;
            line[j] += " ";
            cout << "line[j]: " << line[j] << endl;
        }
        for (int j = 0; j < wordCount; j++) {
            cout << "line 53" << endl;
            cout << "line[" << j << "]: " << line[j] << endl;
            line[j] += string(spacesPerWord, ' ');
            cout << "line[j]: " << line[j] << endl;
        }
        return join(line, " ");
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        while(i < words.size()){
            vector<string> currentLine = getWords(i, words, maxWidth);
            i += currentLine.size();
            result.push_back(createLine(currentLine, i, words, maxWidth));
        }

        return result;
    }
};