/*
    return the maximum number of matching indices after performing any number of right shifts on nums1
    
    Input: nums1 = [1,4,2,5,3,1], nums2 = [2,3,1,2,4,6]
    Output: 3

    [1,4,2,5,3,1] 
    [2,3,1,2,4,6]
*/
class Solution {
public:
    int maximumMatchingIndices(vector<int>& nums1, vector<int>& nums2) {
        int maxCount = 0;
        int n = nums1.size();
        for(int i = 1; i <= n; i++){
            int count = 0;
            for(int j = 0; j < n; j++){
                if(nums1[(j+i)%n] == nums2[j]){
                    count++;
                }
            }
            maxCount = max(count, maxCount);
        }
        return maxCount;
    }
};