class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;
        for(string& word: strs){
            string key = word;
            sort(key.begin(), key.end());
            map[key].push_back(word);
        }

        for(auto it = map.begin(); it != map.end(); it++){
            // vector<string> v = it->second;
            ans.push_back(it->second);
        }

        return ans;
    }
};