/*
    Input: nums = [1,3,5,4,4,6]
    Output: 10

    1 3 5 4 4 6 -> 6
    [1,3] [3,5] [1,3,5] -> 3
    [4,6] -> 1

    [1] [3] [1,3]
    [3,5] [1,3,5] [5]
    [4] [4]
     
     0 1 2 3 4 5
    [1,3,5,4,4,6]

    size  : 1 -> 2 -> 3 -> 1 -> 1 -> 2
    prefix: 1 -> 3 -> 6 -> 7 -> 8 -> 10

    Input: nums = [1,2,3,4,5]
    Output: 15

    [1,2,3,4,5]

    size  : 1 -> 2 -> 3 -> 4  -> 5
    prefix: 1 -> 3 -> 6 -> 10 -> 15
*/
class Solution {
public:
    long long countSubarrays(vector<int>& nums) {
        long long subArrSize = 1;
        long long prefix = 1;

        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i-1]){
                subArrSize++;
            }
            else{
                subArrSize = 1;
            }
            prefix += subArrSize;
        }

        return prefix;
    }
};