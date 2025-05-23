class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int num: nums){
            if(mp[num]++) return true;
        }
        return false;
    }
};