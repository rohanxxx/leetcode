class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.length();
        unordered_map<int, int> freq;
        for(int i = 0; i < min(3, n); i++){
            freq[s[i]-'a']++;
        }

        int count = 0;
        if(freq.size() == 3){
            count++;
        }
        for(int i = 3; i < n; i++){
            freq[s[i-3]-'a']--;
            if(freq[s[i-3]-'a'] == 0){
                freq.erase(s[i-3]-'a');
            }
            freq[s[i]-'a']++;
            if(freq.size() == 3){
                count++;
            }
        }

        return count;
    }
};