class Solution {
public:
    void backtracking (vector<vector<int>>& subsets, vector<int>& curSubSet,
                        vector<int>& nums, int index){
        subsets.push_back(curSubSet);

        for(int i = index; i < nums.size(); i++){
            if(i != index && nums[i] == nums[i-1]) continue;
            curSubSet.push_back(nums[i]);
            backtracking(subsets, curSubSet, nums, i+1);
            curSubSet.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> curSubSet;
        sort(nums.begin(), nums.end());
        backtracking(subsets, curSubSet, nums, 0);
        return subsets;
    }
};