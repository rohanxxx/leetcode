class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.length(), count = 0;
        string ans = "";
        for(int i = n-1; i >= 0; i--){
            if(s[i] != '-'){
                ans.push_back(toupper(s[i]));
                count++;
                if(count == k){
                    count = 0;
                    ans.push_back('-');
                }
            }
        }
        if(ans.size() > 0 && ans.back() == '-') {
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};