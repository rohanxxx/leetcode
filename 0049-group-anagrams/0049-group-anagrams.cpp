class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp_anagram;
        vector<vector<string>> ans;
        for(auto& word: strs){
            string key = word;
            sort(key.begin(), key.end());
            mp_anagram[key].push_back(word);
        }
        for(auto& key: mp_anagram){
            ans.push_back(key.second);
        }
        return ans;
    }
};