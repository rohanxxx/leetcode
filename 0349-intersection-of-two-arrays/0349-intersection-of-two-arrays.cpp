class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set;
        unordered_map<int, int> mp;
        for(auto num1: nums1){
            mp[num1]++;
        }
        for(auto num2: nums2){
            if(mp[num2]){
                set.insert(num2);
            }
        }
        vector<int> ans;
        for(auto var: set){
            ans.push_back(var);
        }

        return ans;
    }
};