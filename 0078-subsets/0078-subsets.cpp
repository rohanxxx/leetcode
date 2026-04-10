/*
    [1,2,3]
    {} {1} {2} {3} {1,2} {1,3} {2,3} {1,2,3}
*/
class Solution {
public:
    void backtrack(vector<vector<int>>& set, vector<int>& nums, vector<int> cur, int idx){
        set.push_back(cur);
        if(idx >= nums.size()) return;
        //if(cur.size() == nums.size()) return;
        
        for(int i = idx; i < nums.size(); i++){
            cur.push_back(nums[i]);
            backtrack(set, nums, cur, i+1);
            cur.pop_back();
        }
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> set;
        backtrack(set, nums, {}, 0);
        //return vector<vector<int>>(set.begin(), set.end());
        return set;
    }
};