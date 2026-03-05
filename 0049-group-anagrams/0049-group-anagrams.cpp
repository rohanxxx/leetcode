class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrams;
        for(auto s: strs){
            vector<int> map(26, 0);
            //TC:O(M)
            for(auto c: s){
                map[c-'a']++;
            }

            string key = "";
            //O(26+M)
            for(int i = 0; i < 26; i++){
                for(int j = 0; j < map[i]; j++){
                    key.push_back(char(i+'a'));
                }
            }
            anagrams[key].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto it: anagrams){
            string key = it.first;
            vector<string> group = it.second;
            ans.push_back(group);
        }

        return ans;
    }
};