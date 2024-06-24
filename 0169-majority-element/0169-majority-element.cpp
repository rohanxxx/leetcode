class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int majorityElement = 0, maxCount = 0;
        for(int i = 0; i < nums.size(); i++){
            mp[nums[i]]++;
            if(maxCount < mp[nums[i]]){
                maxCount = mp[nums[i]];
                majorityElement = nums[i];
            }
        }
        if(mp[majorityElement] > nums.size()/2) return majorityElement;
        return -1;
    }
};