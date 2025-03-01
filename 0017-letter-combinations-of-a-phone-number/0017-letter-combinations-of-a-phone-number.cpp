class Solution {
public:
    vector<string> combinations;
    unordered_map<char, string> phoneBook;
    void backtrack(string& digits, string cur, int index){
        if(cur.length() == digits.length()){
            if(cur == "") return;
            combinations.push_back(cur);
            return;
        }
        int len = phoneBook[digits[index]].length();
        for(int i = 0; i < len; i++){
            cur += phoneBook[digits[index]][i];
            backtrack(digits, cur, index+1);
            cur.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
           phoneBook = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
            {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
           };
           backtrack(digits, "", 0);
           return combinations;
    }
};