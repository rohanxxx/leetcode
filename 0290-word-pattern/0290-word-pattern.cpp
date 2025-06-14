class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> wordMap;
        unordered_map<string, char> charMap;
        vector<string> words;
        
        istringstream ss(s);
        string word = "";
        
        while(ss >> word) words.push_back(word);

        if(words.size() != pattern.size()) return false;

        int n = pattern.size();
        for(int i = 0; i < n; i++){
            char c = pattern[i];
            if(wordMap.count(c)){
                if(wordMap[c] != words[i]) return false;
            }
            else{
                if(charMap.count(words[i])) return false;
                wordMap[c] = words[i];
                charMap[words[i]] = c;
            }
        }

        return true;
    }
};