/*
    arr: nums
    integer: k

    select i and replace nums[i] with nums[i]-1

    return the minimum number of operations required to make the sum of the arr divisible by k

    3+9+7 => 19/5 => 3*5 => 15 => abs(15-19) => 4
    4+1+3 => 8/4 => 2*4 => 4 => abs(8-8) => 0
*/
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum = 0;
        for(auto num: nums)
            sum += num;
        
        return (int)abs((sum/k)*k-sum);
    }
};