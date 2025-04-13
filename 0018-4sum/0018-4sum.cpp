class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        if(nums.size() < 4) return {};
        set <vector<int>> sets;
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size()-3; i++){
            for(int j = i+1; j <nums.size()-2; j++){
                int lo = j+1;
                int hi = nums.size()-1;
                while(lo < hi){
                    long long sum = static_cast<long long>(nums[i]) + nums[j] + nums[lo] + nums[hi];
                    if(sum == target){
                        sets.insert({nums[i], nums[j], nums[lo], nums[hi]});
                        lo++;
                        hi--;
                    }
                    else if (sum < target) lo++;
                    else hi--;
                }
            }
        }
        for(auto set: sets) ans.push_back(set);
        return ans;
    }
};