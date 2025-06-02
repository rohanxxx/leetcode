class Solution {
public:
    //TC: O(N+T)
    //SC: O(52)
    int lengthAfterTransformations(string s, int t) {
        int mod = 1e9+7;
        vector<int> curFreq(26, 0);
        //O(n)
        for(auto c: s) curFreq[c-'a']++;
        //O(26*t)
        for(int i = 0; i < t; i++){
            vector<int> nextFreq(26, 0);
            //O(26)
            for(int j = 0; j < 26; j++){
                int nextIndex = j+1;
                if(nextIndex == 26 && curFreq[j] > 0){
                    nextFreq[0] = (nextFreq[0] + curFreq[j]) % mod;
                    nextFreq[1] = (nextFreq[1] + curFreq[j]) % mod;
                }
                else{
                    if(nextIndex != 26){
                        nextFreq[nextIndex] = (nextFreq[nextIndex]+curFreq[j]) % mod;
                    }
                }
            }
            curFreq = nextFreq;
        }
        int len = 0;
        for(int i = 0; i < 26; i++){
            len = (len + curFreq[i]) % mod;
        }
        return len;
    }
};