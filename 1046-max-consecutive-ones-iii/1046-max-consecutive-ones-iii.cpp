class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left, zeros, maxLen; 
        left = zeros = maxLen = 0;

        for(int i = 0; i < n; i++){
            if(nums[i] == 0) zeros++;
            if(zeros > k){
                // update the left pointer and zero count;
                while(true){
                    if(nums[left] == 0){
                        left++;
                        zeros--;
                        break;
                    }
                    left++;
                }
            }
            maxLen = max(i-left+1, maxLen);
        }
        return maxLen;
    }
};