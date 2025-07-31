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
        vector<int> map1(101), map2(101);
        //O(N+M)
        for(auto& num: nums1) map1[num]++;
        for(auto& num: nums2) map2[num]++;

        int product = 0;
        int i = 0, j = 100;
        //O(101)
        while(i <= 100 && j >= 0){
            while(i <= 100 && map1[i] == 0) i++;
            while(j >= 0 && map2[j] == 0) j--;
            if(i <= 100 && j >= 0){
                product += (i*j);

                //decrement the freq
                map1[i]--;
                map2[j]--;
            }
        }

        return product;
    }
};