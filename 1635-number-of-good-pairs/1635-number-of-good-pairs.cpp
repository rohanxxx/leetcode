class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int goodPairs = 0;
        unordered_map<int, int> mp;
        for(int num: nums){
            goodPairs += mp[num]++;

        }

        return goodPairs;
    }
};