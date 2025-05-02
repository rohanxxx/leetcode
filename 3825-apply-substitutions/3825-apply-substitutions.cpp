/*
    place holder format %v% each var corresponds to a key in the replacement mapping
    each replacement value may itself contain one or more such placeholders
    each placeholder is replaced by the value associated with its corresponding replacement key

    return the fully substituted text string whcih does not contain any placeholders

    ["A","bce"],["B","ace"],["C","abc%B%"] text = "%A%_%B%_%C%"
    bce_ace_abc%B% -> bce_ace_abcace
*/
class Solution {
    unordered_map<string, string> dict;

    int getPlaceholderEndIndex(string &text, int i) {
        while(i < text.size()) {
            if(text[i] == '%') return i;
            i++;
        }
        return -1;
    }

    string helper(string &text, int index) {
        
        string ans = "";

        for(int i=index; i<text.size();) {
            if(text[i] == '%') {
                int j = getPlaceholderEndIndex(text, i+1);
                string placeholder = text.substr(i+1, j - i - 1);

                string key = dict[placeholder];

                key = helper(key, 0); // check again if key contains %xyz%
                ans += key;

                i = j + 1; // forward the i
            } 
            else {
                ans += text[i++]; // text outside of the placeholder
            }
        }

        return ans;
    }
public:
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        for(auto &replacement : replacements) {
            dict[replacement[0]] = replacement[1];
        }

        return helper(text, 0);
    }
};