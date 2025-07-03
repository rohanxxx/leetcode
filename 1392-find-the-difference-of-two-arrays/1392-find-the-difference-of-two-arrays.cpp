class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map1, map2;
        for(auto& num: nums1) map1[num]++;
        for(auto& num: nums2) map2[num]++;

        unordered_set<int> s1, s2;
        for(auto& num: nums1){
            if(map2.find(num) == map2.end()){
                s1.insert(num);
            }
        }

        for(auto& num: nums2){
            if(map1.find(num) == map1.end()){
                s2.insert(num);
            }
        }

        vector<vector<int>> ans(2);
        for(auto& it: s1) ans[0].push_back(it);
        for(auto& it: s2) ans[1].push_back(it);

        return ans;
    }
};