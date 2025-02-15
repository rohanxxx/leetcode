class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int n: nums){
            mp[n]++;
            if(mp[n] == 2){
                ans.push_back(n);
            }
        }

        return ans;
    }
};