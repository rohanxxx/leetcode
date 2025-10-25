/*
    1 2 2
    1 1 2 10
*/
class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        int perimeter = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++){
            if(nums[i]+nums[i+1] > nums[i+2]){
                perimeter = max(perimeter, nums[i]+nums[i+1]+nums[i+2]);
            }
        }
        return perimeter;
    }
};