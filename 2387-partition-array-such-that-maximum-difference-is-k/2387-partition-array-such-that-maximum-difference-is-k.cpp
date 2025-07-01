class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        
        int start = nums[0], count = 1;

        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i]-start > k){
                count++;
                start = nums[i];
            }
        }

        return count;
    }
};