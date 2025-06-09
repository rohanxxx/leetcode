/*
            0 1 2 3 4
    nums = [3,4,5,1,2]
    get the size = 5
    1 index is 3
    start off with index 4 and end with index 7 (3+size-1)
    throughout the process if there is no discrepency then it's true otherwise it's false

*/
class Solution {
public:
    //TC: O(N+N) = O(2N) = O(N)
    //SC: O(1)
    bool check(vector<int>& nums) {
        int n = nums.size();
        int index, minElement = INT_MAX;
        //TC: O(N)
        for(int i = 0; i < n; i++){
            if(minElement > nums[i]){
                index = i;
                minElement = nums[i];
            }
            if(i > 0 && nums[i-1] > nums[i]){
                index = i;
                minElement = nums[i];
            }
        }
        //TC: O(N)
        for(int i = index+1; i < index+n; i++){
            if(nums[i%n] < nums[(i-1)%n]){
                return false;
            }
        }
        return true;
    }
};