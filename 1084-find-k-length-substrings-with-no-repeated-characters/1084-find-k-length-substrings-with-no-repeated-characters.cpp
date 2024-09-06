class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        if(k == 0) return 0;
        if(k == 1) return s.length();
        vector<int> mp(26, -1); mp[s[0]-'a'] = 0;
        
        int count = 0;
        int lastDupAt = 0;
        // cout << "s.size: " << s.length() << endl;
        for(int i = 1; i < s.length(); i++){
            if(mp[s[i]-'a'] == -1){
                
                mp[s[i]-'a'] = i;

                if((i+1) - lastDupAt == k){
                    cout << "i: " << i << endl;
                    count++;
                    lastDupAt++;
                }
                continue;
            }

            if(i-mp[s[i]-'a'] < k && lastDupAt <= mp[s[i]-'a']){
                lastDupAt = mp[s[i]-'a']+1;
                mp[s[i]-'a'] = i;
                continue;
            }

            mp[s[i]-'a'] = i;

            if((i+1)-lastDupAt == k) {
                cout << "i: " << i << endl;
                lastDupAt++;
                count++;
            }
        }

        return count;
    }
};