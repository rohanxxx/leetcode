class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size() < 1) return 0;
        
        int result = nums[0];
        int maxSoFar = nums[0];
        int minSoFar = nums[0];

        for(int i = 1; i < nums.size(); i++){
            int curr = nums[i];
            int temp = max(curr, max(maxSoFar*curr, minSoFar*curr));
            minSoFar = min(curr, min(maxSoFar*curr, minSoFar*curr));
            maxSoFar = temp;
            
            result = max(maxSoFar, result);
        }

        return result;
    }
};