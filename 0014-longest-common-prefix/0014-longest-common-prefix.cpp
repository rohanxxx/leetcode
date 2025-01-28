class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = INT_MAX;
        for(int i = 1; i < strs.size(); i++){
            int prefix = 0;
            for(int j = 0; j < min((int)strs[i-1].length(), (int)strs[i].length()); j++){
                if(strs[i-1][j] == strs[i][j]){
                    prefix++;
                }
                else{
                    // minLen = min(prefix, minLen);
                    break;
                }
            }
            minLen = min(prefix, minLen);
        }
        // cout << "minLen: " << minLen << endl;
        if(minLen == 0) return "";
        return strs[0].substr(0, minLen);
    }
};