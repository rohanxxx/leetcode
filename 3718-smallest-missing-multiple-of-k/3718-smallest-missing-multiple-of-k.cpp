/*
    array nums
    integer k
    return the smallest positive multiple of k that is missing from nums

    a multiple of k is any positive int divisible by k

    Input: nums = [8,2,3,4,6], k = 2
    Output: 10

    2 -> 8 or more the missing number multiplr of 8
    2 4 6 8

                   0 1 2 3  4
    Input: nums = [1,4,7,10,15], k = 5
    Output: 5

    1 -> 15
    step#1 get a set
    step#2 find min and max
    step#3 iterate from min to max

    TC: O(max(N, nums[i]))
    SC: O(N)
*/
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> set(nums.begin(), nums.end());
        int ans = k;
        while(set.count(ans)){
            ans += k;
        }

        return ans;
    }
};