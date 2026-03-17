/*
      1  2  3  4  5
    [-1,-3,-4,-2, 2]
      
      1 2  3 4 5
    [-3,1,-3,4,2]

*/
class Solution {
public:
    //TC: O(N+N) = O(2N)
    //SC: O(1)
    int findDuplicate(vector<int>& nums) {
        int n = nums.size(), dup = -1;

        //TC: O(N)
        for(int i = 0; i < n; i++){
            int index = abs(nums[i])-1;
            if(nums[index] < 0){
                dup = abs(nums[i]);
                break;
            }
            nums[index] *= -1;
        }

        //TC: O(N)
        for(int i = 0; i < n; i++){
            nums[i] = abs(nums[i]);
        }

        return dup;
    }
};