/*
 nums = [3,1,-2,-5,2,-4]
 -2,-5,-4
 3,1,2

 3 -2 1 -5 2 -4
*/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> positive, negative;
        for(auto it: nums){
            if(it < 0) negative.push_back(it);
            else positive.push_back(it);
        }
        int pIndex = 0, nIndex = 0;
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            if(i % 2 == 0) ans[i] = positive[pIndex++];
            else ans[i] = negative[nIndex++];
        }
        return ans;
    }
};