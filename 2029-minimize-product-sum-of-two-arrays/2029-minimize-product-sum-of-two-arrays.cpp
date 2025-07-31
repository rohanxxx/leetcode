class Solution {
public:
    /*
        Input: nums1 = [5,3,4,2], nums2 = [4,2,2,5]
        Output: 40

        2,3,4,5
        2,2,4,5
        10+12+8+10 => 40        
        Explanation: We can rearrange nums1 to become [3,5,4,2]. 
        The product sum of [3,5,4,2] and [4,2,2,5] is 3*4 + 5*2 + 4*2 + 2*5 = 40.

        Input: nums1 = [2,1,4,5,7], nums2 = [3,2,4,8,6]
        Output: 65

        1,2,4,5,7
        2,3,4,6,8

        8+12+16+15+14 => 
    */
    int minProductSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int product = 0;
        for(int i = 0; i < n; i++){
            product += (nums1[i]*nums2[n-i-1]);
        }
        return product;
    }
};