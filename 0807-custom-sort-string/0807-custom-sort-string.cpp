class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> freq(26, 0);
        //get all the freq
        for(auto& c: s){
            freq[c-'a']++;
        }

        string ans = "";
        //now maintain the order
        for(auto& c: order){
            int n = freq[c-'a'];
            for(int i = 0; i < n; i++){
                ans += c;
            }
            freq[c-'a'] = 0;
        }

        for(auto& c: s){
            if(freq[c-'a'] > 0){
                ans += c;
            }
        }

        return ans;
    }
};