class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int bitIndex = 0; bitIndex < 32; bitIndex++){
            int count = 0;
            for(int i = 0; i < n; i++){
                if(nums[i] & (1 << bitIndex)){
                    count++;
                }
            }
            if(count % 3){
                ans = ans | (1 << bitIndex);
            }
        }
        return ans;
    }
};