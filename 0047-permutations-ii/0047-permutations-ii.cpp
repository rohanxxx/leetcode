/*
    nums = [1,1,2]
    1 1 2
    1 
*/
class Solution {
public:
    void backtrack(vector<int>& nums, unordered_map<int, bool>& map, 
                            vector<int>& comb, set<vector<int>>& ans){
        if(comb.size() == nums.size()){
            ans.insert(comb);
            return;
        }

        for(int i = 0; i < nums.size(); i++){
            if(map[i] == false){
                map[i] = true;
                comb.push_back(nums[i]);
                backtrack(nums, map, comb, ans);
                comb.pop_back();
                map[i] = false;
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, bool> indexMap;
        set<vector<int>> ans;
        vector<int> temp;
        backtrack(nums, indexMap, temp, ans);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};