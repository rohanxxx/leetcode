class Solution {
public:
/*
    2 1
    1 0 -> 2
    1 0 -> 2
    0 0
    0 1
    0 1 -> 1*/
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            ans ^= nums[i];
        }
        return ans;
    }
};