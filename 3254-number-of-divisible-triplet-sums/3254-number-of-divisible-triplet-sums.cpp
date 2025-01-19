class Solution {
public:
    int divisibleTripletCount(vector<int>& nums, int d) {
        unordered_map<int, int> mp;

        int n = nums.size(), count = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int rem = (d - (nums[i]+nums[j]) % d) % d; 
                count += mp[rem];
            }
            mp[nums[i] % d]++;
        }

        return count;
    }
};