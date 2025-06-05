class Solution {
public:
    string triangleType(vector<int>& nums) {
        if(nums[0] + nums[1] <= nums[2]) return "none";
        if(nums[0] + nums[2] <= nums[1]) return "none";
        if(nums[1] + nums[2] <= nums[0]) return "none";

        unordered_map<int, int> freq;
        for(auto num: nums) freq[num]++;
        if(freq.size() == 3) return "scalene";
        if(freq.size() == 2) return "isosceles";
        return "equilateral";
    }
};