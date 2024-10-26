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
};