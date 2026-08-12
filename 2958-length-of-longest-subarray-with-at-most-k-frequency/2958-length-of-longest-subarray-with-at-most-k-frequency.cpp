class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> hashmap;

        int ans = 0;
        int n = nums.size(), left = 0;
        for(int right = 0; right < n; right++){
            hashmap[nums[right]]++;
            while(left <= right && hashmap[nums[right]] > k){
                hashmap[nums[left]]--;
                left++;
            }

            ans = max(ans, right-left+1);
        }

        return ans;
    }
};