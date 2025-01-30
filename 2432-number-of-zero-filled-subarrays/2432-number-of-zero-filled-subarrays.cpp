class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0, subArrSum = 0;
        for(int num: nums){
            if(num == 0) subArrSum++;
            else subArrSum = 0;
            count += subArrSum;
        }
        return count;
    }
};