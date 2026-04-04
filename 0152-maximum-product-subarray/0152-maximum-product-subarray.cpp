class Solution {
public:
    int maxProduct(vector<int>& nums) {
        const int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        int maxProduct = INT_MIN;
        for(int i = 0; i < n; i++){
            prefix *= nums[i];
            maxProduct = max(maxProduct, prefix);
            if(prefix == 0){
                prefix = 1;
            }
        }
        for(int i = n-1; i >= 0; i--){
            suffix *= nums[i];
            maxProduct = max(maxProduct, suffix);
            if(suffix == 0){
                suffix = 1;
            }
        }
        return maxProduct;
    }
};