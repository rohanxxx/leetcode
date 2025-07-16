class Solution {
public:
    vector<int> orArray(vector<int>& nums) {
        int n = nums.size()-1;
        
        vector<int> ans;
        for(int i = 0; i < n; i++){
            ans.push_back(nums[i]|nums[i+1]);
        }
        
        return ans;
    }
};