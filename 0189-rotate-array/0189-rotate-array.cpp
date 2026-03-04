/*
            0 1 2 3 4 5 6
    nums = [1,2,3,4,5,6,7], k = 3
            5 6 7 1 2 3 4

            k * n
            for i -> k:
                for j -> num:
                    {
                        shift by 1 
                    }
            0+k%n =>     
            
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            int index = (i+k)%n;
            ans[index] = nums[i];
        }

        nums = ans;
    }
};