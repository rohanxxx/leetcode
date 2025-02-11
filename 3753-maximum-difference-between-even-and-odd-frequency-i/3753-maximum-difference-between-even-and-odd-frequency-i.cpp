class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;
        for(char c: s){
            mp[c]++;
        }

        int maxOdd = INT_MIN, minOdd = INT_MAX;
        int maxEven = INT_MIN, minEven = INT_MAX;
        for(auto c: mp){
            if((int)c.second % 2){
                maxOdd = max(maxOdd, (int)c.second);
                minOdd = min(minOdd, (int)c.second);
            }
            else{
                maxEven = max(maxEven, (int)c.second);
                minEven = min(minEven, (int)c.second);
            }
        }

        int maxDif = max((maxOdd-minEven), (minOdd-maxEven));
        return maxDif;
    }
};