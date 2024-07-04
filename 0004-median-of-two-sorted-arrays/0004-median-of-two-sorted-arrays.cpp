class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> nums = nums1;
        for(auto& num2: nums2) nums.push_back(num2);

        sort(nums.begin(), nums.end());
        //odd case
        if(nums.size()%2){
            return static_cast<double>(nums[nums.size()/2]);
        }

        return (static_cast<double>(nums[nums.size()/2])+nums[nums.size()/2-1])/2;
    }
};