class Solution {
public:
    int calculateTime(string keyboard, string word) {
        unordered_map<char, int> mp;
        for(int i = 0; i < keyboard.length(); i++){
            mp[keyboard[i]] = i;
            // cout << keyboard[i] << ": " << i << endl;
        }

        int typingTime = abs(mp[word[0]]-0);
        // cout << typingTime << endl;
        for(int i = 1; i < word.length(); i++){
            typingTime += abs(mp[word[i]] - mp[word[i-1]]);
            // cout << typingTime << endl;
        }
        return typingTime;
    }
};