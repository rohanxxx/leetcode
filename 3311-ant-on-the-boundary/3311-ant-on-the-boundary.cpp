class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int antLocation = nums[0], count = 0;
        
        if(antLocation == 0) count++;
        for(int i = 1; i < nums.size(); i++){
            antLocation += nums[i];
            if(antLocation == 0) count++;
        }

        return count;
    }
};