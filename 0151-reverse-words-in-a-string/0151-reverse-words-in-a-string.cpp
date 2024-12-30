class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        
        // stringstream object
        stringstream ss(s);
        
        string word = "";
        while(ss >> word){
            words.push_back(word);
        }

        int size = words.size();
        string sentence = "";
        for(int i = size-1; i >= 0; i--){
            sentence += (words[i]+" ");
        }
        sentence.pop_back();
        return sentence;
    
    }
};