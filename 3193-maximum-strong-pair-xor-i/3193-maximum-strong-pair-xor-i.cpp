class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        int XOR = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = i; j < nums.size(); j++){
                if(abs(nums[i]-nums[j]) <= (int)min(nums[i], nums[j])){
                    int temp = nums[i];
                    temp ^= nums[j];
                    XOR = max(XOR, temp);
                }
            }
        }
        return XOR;
    }
};