/*
     0123
    "a1b2"
     a1b2
     A1b2
     a1B2
     A1B2


*/

void backtrack(int i, string& s, string& curr, unordered_set<string>& myset){
    if(i == s.length()){
        myset.insert(curr);
        return;
    }

    
    if(isalpha(s[i]) == false){
        curr.push_back(s[i]);
        backtrack(i+1, s, curr, myset);
        curr.pop_back();
        return;
    }

    curr.push_back(toupper(s[i]));
    backtrack(i+1, s, curr, myset);
    curr.pop_back();
        
    curr.push_back(tolower(s[i]));
    backtrack(i+1, s, curr, myset);
    curr.pop_back();
    
}
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        unordered_set<string> myset;

        string curr = "";
        backtrack(0, s, curr, myset);

        vector<string> ans(myset.begin(), myset.end());

        return ans;
    }
};