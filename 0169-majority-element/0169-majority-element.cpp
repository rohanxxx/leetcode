class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int size = nums.size();
        int maxCount = 0;
        int maxElement = 0;
        for(int n: nums){
            if(++mp[n] > (size/2)){
                if(maxCount < mp[n]){
                    return maxElement = n;
                }
            }
        }
        return maxElement;
    }
};