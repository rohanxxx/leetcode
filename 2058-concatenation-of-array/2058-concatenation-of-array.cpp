//0 1 2 3
//0 1 2 3 4
class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(2*n, 0);
        for(int i = 0; i < n; i++){
            ans[i] = ans[i+n] = nums[i];
        }

        return ans;
    }
};