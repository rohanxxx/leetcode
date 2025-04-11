class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0 = 0, cur = 0, p2 = nums.size()-1;
        while(cur <= p2){
            if(nums[cur] == 2){
                swap(nums[cur], nums[p2]);
                p2--;
            }
            else{
                if(nums[cur] == 0){
                    swap(nums[cur++], nums[p0]);
                    p0++;
                }
                else cur++;
            }
            // cur++;
        }
    }
};