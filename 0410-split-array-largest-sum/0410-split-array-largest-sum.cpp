/*
    nums = [7,2,5,10,8], k = 2 
    25, 23, 18, 24
*/

class Solution {
public:
    unordered_map<string, long long> dp;

    long long dfs(int i, int m, vector<int>& nums) {
        if (m == 1) {
            long long sum = 0;
            for (int j = i; j < nums.size(); j++) {
                sum += nums[j];
            }
            return sum;
        }

        string key = to_string(i) + "," + to_string(m);
        if (dp.count(key)) return dp[key];

        long long res = LLONG_MAX;
        long long curSum = 0;

        for (int j = i; j <= nums.size() - m; j++) {
            curSum += nums[j];
            long long maxSum = max(curSum, dfs(j + 1, m - 1, nums));
            res = min(res, maxSum);

            if (curSum > res) break;
        }

        dp[key] = res;
        return res;
    }

    int splitArray(vector<int>& nums, int m) {
        dp.clear();
        return dfs(0, m, nums);
    }
};
/*
class Solution {
public:
    
    int memo[1001][51];
    
    int largestMinSumSplit(vector<int> &prefixSum, int curIndex, int subArrayCount){
        int n = prefixSum.size()-1;

        if(memo[curIndex][subArrayCount] != -1){
            return memo[curIndex][subArrayCount];
        }
        if(subArrayCount == 1){
            return memo[curIndex][subArrayCount] = prefixSum[n]-prefixSum[curIndex];
        }

        int minimumLargestSumSplit = INT_MAX;
        for(int i = curIndex; i <= n - subArrayCount; i++){
            int firstSplitSum = prefixSum[i+1] - prefixSum[curIndex];
            int largestSplitSum = max(firstSplitSum, largestMinSumSplit(prefixSum, i+1, subArrayCount-1));
            minimumLargestSumSplit = min(minimumLargestSumSplit, largestSplitSum);  

            if(firstSplitSum >= minimumLargestSumSplit){
                break;
            }
        }

        return memo[curIndex][subArrayCount] = minimumLargestSumSplit;
    }

    int splitArray(vector<int>& nums, int k) {
        memset(memo, -1, sizeof(memo));
        int n = nums.size();
        vector<int> prefixSum (n+1, 0);
        for(int i = 1; i < n+1; i++){
            prefixSum[i] += (prefixSum[i-1]+nums[i-1]);
        }
        return largestMinSumSplit(prefixSum, 0, k);
    }
};*/