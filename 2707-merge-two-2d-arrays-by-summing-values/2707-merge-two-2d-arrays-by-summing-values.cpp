class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int, int> map;
        for(auto& num: nums1){
            map[num[0]] += num[1];
        }
        for(auto& num: nums2){
            map[num[0]] += num[1];
        }

        vector<vector<int>> ans;
        for(auto it: map){
            ans.push_back({it.first, it.second});
        }
        return ans;
    }
};