class Solution {
public:
    int storeFirstOptions(string& s, int startPos, vector<char>& firstOptions){
        if(s[startPos] != '{'){
            firstOptions.push_back(s[startPos]);
        }
        else{
            while(s[startPos] != '}'){
                if(s[startPos] >= 'a' && s[startPos] <= 'z'){
                    firstOptions.push_back(s[startPos]);
                }
                startPos++;
            }

            sort(firstOptions.begin(), firstOptions.end());
        }

        return startPos+1;
    }
    vector<string> findAllWords(string& s, int startPos){
        if(startPos == s.length()) return {""};
        
        vector<char> firstOptions;
        
        int remStringStartPos = storeFirstOptions(s, startPos, firstOptions);
        vector<string> wordsWithRemString = findAllWords(s, remStringStartPos);
        
        vector<string> expandedWords;
        for(char c: firstOptions){
            for(string word: wordsWithRemString){
                expandedWords.push_back(c+word);
            }
        }
        
        return expandedWords;
    }

    vector<string> expand(string s) {
        return findAllWords(s, 0);
    }
};