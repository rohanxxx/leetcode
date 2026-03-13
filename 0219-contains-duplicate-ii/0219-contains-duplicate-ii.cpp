/*
            0 1 2 3
    nums = [1,2,3,1], k = 3
    0-3 = 3 <= 3 1==1 true

    if(mp.find(num[i]) != mp.end() && abs(i-j) <= k){
        return true;
    }

    key = nums[i] val = i
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        //key = nums[i], val = i
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            if(mp.find(nums[i]) != mp.end() && abs(mp[nums[i]]-i) <= k){
                return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};