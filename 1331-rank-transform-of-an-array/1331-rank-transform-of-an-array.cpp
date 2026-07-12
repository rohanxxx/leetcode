class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        map<int, vector<int>> numToIndex;
        for(int i = 0; i < n; i++){
            numToIndex[arr[i]].push_back(i);
        }

        int rank = 1;
        vector<int> ans(n, 0);
        for(auto it: numToIndex){
            for(int index: it.second){
                ans[index] = rank;
            }
            rank++;
        }

        return ans;
    }
};