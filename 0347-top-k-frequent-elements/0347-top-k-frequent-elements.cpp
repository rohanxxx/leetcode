class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int num: nums) freq[num]++;
        vector<vector<int>> bucket(nums.size()+1);
        for(auto it: freq){
            bucket[it.second].push_back(it.first);
        }

        vector<int> ans;
        for(int i = nums.size(); i >= 0; i--){
            if(bucket[i].size()){
                for(auto it: bucket[i]){
                    ans.push_back(it);
                    if(ans.size()>k){
                        ans.pop_back();
                        return ans;
                    }
                }
            }
        }

        return ans;
    }
};