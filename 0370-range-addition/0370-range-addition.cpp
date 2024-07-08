class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> ans(length, 0);
        for(int i = 0; i < updates.size(); i++){
            for(int j = updates[i][0]; j <= updates[i][1]; j++){
                ans[j] += updates[i][2];
            }
        }
        return ans;
    }
};