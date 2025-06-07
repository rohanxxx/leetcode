/*
    nums = [1,1,2,1,1], k = 3
    
    [1,1,2,1,1]

    nums = [2,2,2,1,2,2,1,2,2,2], k = 2
     0 1 2 3 4 5 6 7 8 9
      [2,2,2,1,2,2,1,2,2,2]
    1) 2 2 2 1 2 2 1
    2) 2 2 2 1 2 2 1 2
    3) 2 2 2 1 2 2 1 2 2
    4) 2 2 2 1 2 2 1 2 2 2
    5) 2 2 1 2 2 1 2 2 2
    6) 2 2 1 2 2 1 2 2

*/
class Solution {
public:
    int func(vector<int>& nums, int k){
        int left, sum, count;
        left = sum = count = 0;
        int n = nums.size();
        for(int right = 0; right < n; right++){
            sum += (nums[right]%2);
            while(sum > k){
                sum = sum - nums[left]%2;
                left++;
            }
            count += (right - left + 1);
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return func(nums, k) - func(nums, k-1);
    }
};