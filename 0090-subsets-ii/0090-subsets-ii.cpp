class Solution {
public:
/*
    void backtrack(vector<int> v, vector<int>&nums){
        for(i->n){
            v.push_back(nums[i]);
            backtrack(v,nums);
            v.pop_back();
        }
    }
*/
    void backtracking (set<vector<int>>& subsets, vector<int>& curSubSet,
                        vector<int>& nums, int index){
        subsets.insert(curSubSet);

        for(int i = index; i < nums.size(); i++){
            //if(i != index && nums[i] == nums[i-1]) continue;
            curSubSet.push_back(nums[i]);
            backtracking(subsets, curSubSet, nums, i+1);
            curSubSet.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> subsets;
        vector<int> curSubSet;
        sort(nums.begin(), nums.end());
        backtracking(subsets, curSubSet, nums, 0);
        return vector<vector<int>>(subsets.begin(), subsets.end());
    }
};