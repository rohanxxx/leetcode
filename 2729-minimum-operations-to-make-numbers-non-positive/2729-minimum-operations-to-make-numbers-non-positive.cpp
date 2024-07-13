class Solution {
public:
    bool dp(vector<int>& nums, long long mid, int x, int y){
        int difference = x-y, size = nums.size();
        long long cost = 0;
        for(auto& num: nums){
            cost += max(0LL, (num-mid*y+difference-1)/difference);
        }
        return cost <= mid;
    }
    int minOperations(vector<int>& nums, int x, int y) {
        long long left = 0, right = 0;
        for(auto& num: nums){
            right += ((num+x-1)/x);
        }

        long long mid;
        while(left <= right){
            mid = (left+right)/2;
            if(dp(nums, mid, x, y)) right = mid-1;
            else left = mid+1;
        }
        return left;
    }
};