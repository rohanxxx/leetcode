class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int minSum = INT_MAX;
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
            int m = mp[nums[i]].size();

            if(m >= 3) {
                int a = mp[nums[i]][m - 3];
                int b = mp[nums[i]][m - 2];
                int c = mp[nums[i]][m - 1];

                int sum = abs(a - b) + abs(a - c) + abs(b - c);
                minSum = min(minSum, sum);
            }
        }
        if(minSum != INT_MAX){
            return minSum;
        }
        return -1;
    }
};