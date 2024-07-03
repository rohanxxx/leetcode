class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 0) return 0;
        
        vector<int> maxRobbedAmount(size+1, 0);
        maxRobbedAmount[size-1] = nums[size-1];

        for(int i = size-2; i >= 0; i--){
            maxRobbedAmount[i] = max(maxRobbedAmount[i+1], maxRobbedAmount[i+2]+nums[i]);
        }

        return maxRobbedAmount[0];
    }
};