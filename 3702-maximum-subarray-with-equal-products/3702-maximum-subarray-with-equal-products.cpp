class Solution {
public:
    int maxLength(vector<int>& nums) {
        int maxLen = 0;
        for(int i = 0; i < nums.size(); i++){
            int product = 1;
            int gcdVal = nums[i], lcmVal = nums[i];
            for(int j = i; j < nums.size(); j++){
                product *= (long long)nums[j];
                gcdVal = gcd(gcdVal, nums[j]);
                lcmVal = lcm(lcmVal, nums[j]);
                if(product == (gcdVal*lcmVal)){
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }
        return maxLen;
    }
};