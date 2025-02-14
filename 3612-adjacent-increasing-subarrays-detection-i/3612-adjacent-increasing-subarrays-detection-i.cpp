class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int count = 0, prevCount = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(i == 0){
                count++;
                continue;
            }
            if(nums[i] > nums[i-1]){
                count++;
                if((count % k == 0) && (count / k > 1)){
                    return true;
                }
                else{
                    if(count % k == 0 && prevCount >= k){
                        return true;
                    }
                }
            }
            else{
                prevCount = count;
                count = 1;
                if(prevCount >= k && count >= k){
                    return true;
                }
            }
        }
        return false;
    }
};