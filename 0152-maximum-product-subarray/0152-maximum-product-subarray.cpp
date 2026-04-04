class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        int maxProduct = INT_MIN;
        for(int i = 0; i < n; i++){
            prefix *= nums[i];
            suffix *= nums[n-i-1];
            maxProduct = max({maxProduct, prefix, suffix});
            if(prefix == 0){
                prefix = 1;
            }
            if(suffix == 0){
                suffix = 1;
            }
        }
        return maxProduct;
    }
};