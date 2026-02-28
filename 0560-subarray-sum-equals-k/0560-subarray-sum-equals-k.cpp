/*
    0 -> 1
    1 -> 1

    0 -> 1
    1 -> 1
    3 -> 1
    6 -> 1 
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), count = 0, sum = 0;
        unordered_map<int, int> prefix; prefix[0] = 1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            if(prefix[sum-k] > 0){
                count += prefix[sum-k];
            }
            prefix[sum]++;
        }
        return count;
    }
};