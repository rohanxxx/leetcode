class Solution {
public:
    unordered_map<char, string> letters;
    vector<string> combinations;
    string phoneDigits;

    void backtrack(int index, string curr){
        if(phoneDigits.length() == curr.length()) {
            combinations.push_back(curr);
            return;
        }

        for(int i = 0; i < letters[phoneDigits[index]].length(); i++){
            char l = letters[phoneDigits[index]][i];
            curr += l;
            backtrack(index+1, curr);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length() < 1) return {};

        letters = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };

        phoneDigits = digits;
        backtrack(0,"");
        return combinations;
    }
};