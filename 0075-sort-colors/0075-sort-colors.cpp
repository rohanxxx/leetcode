class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p1 = 0;
        int p2 = 0;
        int p3 = nums.size()-1;

        while(p2 <= p3){
            if(nums[p2] == 2){
                swap(nums[p2], nums[p3]);
                p3--;
            }
            else{
                if(nums[p2] == 0){
                    swap(nums[p2], nums[p1]);
                    p1++; p2++;
                }
                else{
                    p2++;
                }
            }
        }
    }
};