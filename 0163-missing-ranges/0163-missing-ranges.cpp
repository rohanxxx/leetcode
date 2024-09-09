class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {

        vector<vector<int>> result;
        
        if(nums.size() == 0) {
            result.push_back({lower, upper});
            return result;
        }

        if(nums[0]-lower > 0){
            result.push_back({lower, nums[0]-1});
        }

        for(int i = 0; i < nums.size()-1; i++){
            if(nums.size()>1){
                if(nums[i+1] - nums[i] > 1){
                    if(nums[i+1] <= upper) {
                        result.push_back({nums[i]+1, nums[i+1]-1});
                    }
                    else {
                        result.push_back({nums[i]+1, upper});
                    }
                }
            }
        }

        if(nums.back() < upper){
            result.push_back({nums.back()+1, upper});
        }

        return result;
    }
};