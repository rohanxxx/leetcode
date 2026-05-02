class Solution {
public:
    string reverseWords(string s) {
        istringstream ss(s);

        string ans = "", word = "";
        while(ss >> word){
            ans = word + " " + ans;
        }
        if(!ans.empty()){
            ans.pop_back();
        }

        return ans;
    }
};