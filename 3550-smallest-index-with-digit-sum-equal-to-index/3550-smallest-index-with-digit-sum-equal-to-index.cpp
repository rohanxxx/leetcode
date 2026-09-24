/*
    return the smallest index i such that sum of the digits of nums[i] is equal to i
    if not return -1
*/
class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        //TC: O(N*log10)
        for(int i = 0; i < n; i++){
            int x = nums[i];

            int digitSum = 0;
            //log10
            while(x){
                int digit = x % 10;
                x = x/10;

                digitSum += digit;
            }

            if(digitSum == i){
                return i;
            }
        }

        return -1;
    }
};