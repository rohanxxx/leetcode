class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        for(char& c: t) mp[c]++;

        int left = 0, right = 0;

        int counter = t.length();

        int startIndex = 0;
        int minLen = INT_MAX;

        int size = s.length();
        while(right < size){
            if(mp[s[right]] > 0) counter--;
            
            mp[s[right]]--;
            right++;
            
            while(counter == 0){
                if(right-left < minLen){
                    startIndex = left;
                    minLen = right-left;
                }

                mp[s[left]]++;
                if(mp[s[left]] > 0) counter++;

                left++;
            }

        }

        if(minLen != INT_MAX) return s.substr(startIndex, minLen);
        return "";
    }
};