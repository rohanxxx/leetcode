class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int strictlyIncreasing = 1;
        int strictlyDecreasing = 1;

        int maxOrder = 1;

        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]) {
                strictlyIncreasing++;
                maxOrder = max(maxOrder, strictlyIncreasing);
            }
            else{
                strictlyIncreasing = 1;
            }
        }

        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i-1]) {
                strictlyDecreasing++;
                maxOrder = max(maxOrder, strictlyDecreasing);
            }
            else{
                strictlyDecreasing = 1;
            }
        }

        return maxOrder;
    }
};