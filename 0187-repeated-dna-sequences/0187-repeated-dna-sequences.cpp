class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int len = 10, size = s.length();
        unordered_set<string> seen, ans;
        for(int start = 0; start < size-len+1; start++){
            string subString = s.substr(start, len);
            if(seen.find(subString) != seen.end()) ans.insert(subString);
            seen.insert(subString);
        }
        return vector<string>(ans.begin(), ans.end());
    }
};