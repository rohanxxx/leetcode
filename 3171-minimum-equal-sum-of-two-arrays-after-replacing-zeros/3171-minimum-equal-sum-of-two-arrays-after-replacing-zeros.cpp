class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zero1 = 0, zero2 = 0;
        long long sum1 = 0, sum2 = 0;
        
        for(auto& num1: nums1){
            if(num1 == 0) zero1++;
            sum1 += num1;
        }
        for(auto& num2: nums2){
            if(num2 == 0) zero2++;
            sum2 += num2;
        }

        if(zero1 == 0 && sum1 < sum2+zero2 || zero2 == 0 && sum2 < sum1+zero1) return -1;
        return max(sum1+zero1, sum2+zero2);
    }
};