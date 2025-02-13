class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0, start = -1;
        unordered_map<int, int> mp;
        if(n <= 3){
            for(int i = 0; i < n; i++){
                if(mp.find(nums[i]) != mp.end()){
                    return count = 1;
                }
                mp.insert({nums[i], i});
            }
            return 0;
        }
        for(int i = 0; i < n; i++){
            if(mp.find(nums[i]) != mp.end()){
                while(start < mp[nums[i]]){
                    start += 3;
                    count++;
                }
            }
            mp[nums[i]] = i;
        }
        return count;
    }
};