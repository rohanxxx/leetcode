class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        set<vector<int>> set;
        for(int i = 0; i < nums.size(); i++){
            int j = i + 1, k = nums.size()-1;
            while(j < k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0){
                    set.insert({nums[i], nums[j], nums[k]});
                    j++;
                }
                else{
                    if(sum < 0) j++;
                    else k--;
                }
            }
        }

        vector<vector<int>> ans;
        for(auto& v: set){
            ans.push_back(v);
        }
        
        return ans;
    }
};