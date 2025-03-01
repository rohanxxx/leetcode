class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<int> count(26);
        unordered_map<string, vector<string>> mp;
        for(string s: strs){
            fill(count.begin(), count.end(), 0);
            for(char c: s){
                count[c-'a']++;
            }
            string key = "";
            for(int i = 0; i < 26; i++){
                if(count[i] != 0){
                    key += '#';
                    key += to_string(i);
                    key += to_string(count[i]);
                }
            }
            mp[key].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto m: mp){
            ans.push_back(m.second);
        }
        return ans;
    }
};