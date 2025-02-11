class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int leftSum = 0, rightSum = 0;
        for(int n: nums){
            rightSum += n;
        }

        int count = 0;
        for(int i = 0; i < nums.size()-1; i++){
            leftSum += nums[i];
            rightSum -= nums[i];
            if((leftSum-rightSum)%2 == 0){
                count++;
            }
        }

        return count;
    }
};