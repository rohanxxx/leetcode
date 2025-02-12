class Solution {
public:
    int maxLength(vector<int>& nums) {
        int maxLen = 0;
        for(int i = 0; i < nums.size(); i++){
            int product = 1;
            int gcdVal = nums[i];
            int lcmVal = nums[i];

            int maxLcm = 1e9;

            for(int j = i; j < nums.size(); j++){
                product = product*(long long)nums[j];
                if(product > maxLcm){
                    break;
                }
                gcdVal = gcd(gcdVal, (long long)nums[j]);
                lcmVal = lcm(lcmVal, (long long)nums[j]);
                if(product == (gcdVal*lcmVal)){
                    maxLen = max(maxLen, j-i+1);
                }
            }
        }

        return maxLen;
    }
};