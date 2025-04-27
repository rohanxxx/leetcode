class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length(), left, maxFreq, maxLen;
        left = maxFreq = maxLen = 0;
        vector<int> map(26, 0);
        for(int right = 0; right < n; right++){
            map[s[right]-'A']++;
            maxFreq = max(maxFreq, map[s[right]-'A']);
            int curWindow = right-left+1;
            while(curWindow-maxFreq > k){
                map[s[left]-'A']--;
                left++;
                curWindow = right-left+1;
            }
            curWindow = right-left+1;
            if(curWindow-maxFreq <= k){
                maxLen = max(maxLen, curWindow);
            }
        }
        return maxLen;
    }
};