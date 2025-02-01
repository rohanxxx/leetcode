class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> mp(26);
        for(int i = 0; i < s.length(); i++){
            mp[s[i]-'a'].push_back(i);
        }

        int count = (int)words.size();
        for(string w: words){
            for(int i = 0, j = -1; i < w.length(); i++){
                auto index = upper_bound(mp[w[i]-'a'].begin(), mp[w[i]-'a'].end(), j);
                // means not found
                if(index == mp[w[i]-'a'].end()){
                    count--;
                    break;
                }
                j = *index;
            }
        }

        return count;
    }
};