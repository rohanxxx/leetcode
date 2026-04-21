/*
            0 1 2 3 4 5
    nums = [0,1,7,4,4,5], lower = 3, upper = 6
    O(N^2)
    0+1 0+7x 0+4 0+4 0+5
    1+7x 1+4 1+4 1+5
    7+4x 7+4x 7+5x
    4+4x 4+5x
    4+5x

            0 1 2 3 4 5
    nums = [0,1,7,4,4,5]
            0,1,4,4,5,7
            NlogN + NlogN => 2NlogN => NlogN
            upperBound 6-0 -> 6 && lowerBound 3-0 -> 3
            sort() NlogN
            NlogN
            for(i-n){
                logN
                binarySearch ()
            }

            0 1 2 3 4 5
            0,1,4,4,5,7

            1-> 3-1=>2 6-1=>5
            if(4 > lowerBound){
                4-1
            }
            else lowerBound - nums[i]
            
            if(nums[i] > upperBound) skip
            else upperBound-nums[i]

            lower => 3 && upper => 6
            0+5/2 => 2 -> 0+3/2 return right
            2 -> 2+5/2 => 3 3+5/2 => 4 return left 5-1-1 => 3


*/
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;

        for(int i = 0; i < n; i++){
            long long i_lower = lower - nums[i];
            long long i_upper = upper - nums[i];

            // search only in right side
            int li = lower_bound(nums.begin() + i + 1, nums.end(), i_lower) - nums.begin();
            int ui = upper_bound(nums.begin() + i + 1, nums.end(), i_upper) - nums.begin();

            count += (long long)(ui - li);
        }

        return count;
    }
};