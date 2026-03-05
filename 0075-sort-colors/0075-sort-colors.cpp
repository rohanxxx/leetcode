/*
    nums = [2,0,2,1,1,0]
            0 1 2 3 4 5
            0 0 1   2 2
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p1 = 0, p2 = 0, p3 = nums.size()-1;
        while(p2 <= p3){
            if(nums[p2] == 2){
                swap(nums[p2], nums[p3]);
                p3--;
            }
            else if(nums[p2] == 0){
                swap(nums[p1], nums[p2]);
                p2++; p1++;
            }
            else{
                p2++;
            }
        }
    }
};