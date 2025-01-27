class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros = 0, left = 0;
        int currentLen = 0, maxLen = 0;
        for(int right = 0; right < nums.size(); right++){
            if(nums[right] == 0) zeros++;
            if(zeros > k){
                while(left <= right){
                    if(nums[left++] == 0) {
                        zeros--;
                        break;
                    }
                }
            }
            int currentLen = (right - left) + 1;
            maxLen = max(maxLen, currentLen);
        }

        return maxLen;
    }
};