class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0, maxLen = 0, maxFreq = 0;
        
        vector<int> map(26, 0);
        for(int right = 0; right < s.length(); right++){
            maxFreq = max(maxFreq, ++map[s[right] - 'A']);
            while(((right-left+1)-maxFreq) > k){
                map[s[left++]-'A']--; //maxFreq = 0;
                //for(int mp: map) maxFreq = max(maxFreq, mp);
            }

            if((right-left+1)-maxFreq <= k){ 
                maxLen = max(maxLen, right-left+1);
            }
        }
        return maxLen;
    }
};