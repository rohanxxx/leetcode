class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        unordered_set<int> set;
        for(auto num: nums){
            mini = min(mini, num);
            maxi = max(maxi, num);
            set.insert(num);
        }

        vector<int> ans;
        for(int i = mini; i <= maxi; i++){
            if(set.count(i) == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};