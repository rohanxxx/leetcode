class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //TC: O(NlogN)
        sort(nums.begin(), nums.end());
        set<vector<int>> set;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            int lo = i+1;
            int hi = n-1;
            while(lo < hi){
                if(nums[i] + nums[lo] + nums[hi] == 0){
                    set.insert({nums[i], nums[lo], nums[hi]});
                    lo++;
                }
                else if(nums[i] + nums[lo] + nums[hi] < 0){
                    lo++;
                }
                else{
                    hi--;
                }
            }
        }

        vector<vector<int>> ans(set.begin(), set.end());
        return ans;
    }
};