/*
             0. 1. 2 3 4.           0.  1. 2. 3. 4.
    nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
             0 1 2.           0. 1. 2
    nums1 = [2,2,2], nums2 = [10,10,1]
*/
class Solution {
public:
    //TC: O(N+M)
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int i = n-1, j = m-1;

        int maxDis = 0;
        while(i >= 0 && j >= 0){
            /*if(i > j){
                i--;
                continue;
            }*/
            if(nums1[i] > nums2[j]){
                j--;
                continue;
            }
            //otherwise it's a valid pair
            maxDis = max(maxDis, j-i);
            i--;
        }
        return maxDis;
    }
};