class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int oneCount = 0;

        string ans = "";

        int left = 0;
        for(int right = 0; right < n; right++){
            if(s[right] == '1'){
                oneCount++;
            }
            while(left <= right && oneCount == k){
                if(ans.size() == (right-left+1)){
                    ans = min(ans, (string)s.substr(left, right-left+1));
                }
                if(ans.size() > right-left+1 || ans == ""){
                    ans = s.substr(left, right-left+1);
                }
                if(s[left] == '1'){
                    oneCount--;
                }
                left++;
            }
        }
        return ans;
    }
};