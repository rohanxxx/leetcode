class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int n = min(strs[0].size(), strs.back().size());

        string ans = "";
        for(int i = 0; i < n; i++){
            if(strs[0][i] == strs.back()[i]) ans += strs[0][i];
            else return ans;
        }
        return ans;
    }
};