class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        for(char c: s){
            if(isdigit(c) && !ans.empty()){
                ans.pop_back();
                continue;
            }
            ans += c;
        }
        return ans;
    }
};