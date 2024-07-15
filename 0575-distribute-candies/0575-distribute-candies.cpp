class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int count = 0;
        unordered_map<int, int> mp;
        for(auto& candy: candyType){
            if(!mp[candy]) count++;
            mp[candy]++;
        }
        int maxCandies = candyType.size()/2;
        return min(count, maxCandies);
    }
};