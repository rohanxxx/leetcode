/*
    nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2

     0 1 2 3 4 5 6 7 8 9 10
    [1,1,1,0,0,0,1,1,1,1,0]
*/
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, maxLen = 0;
        for(int right = 0; right < n; right++){
            if(nums[right] == 0) k--;
            while(k < 0){
                if(nums[left] == 0) k++;
                left++;
            }
            maxLen = max(maxLen, right-left+1);
        }
        return maxLen;
    }
};