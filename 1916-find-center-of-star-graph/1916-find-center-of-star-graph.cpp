class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, int> mp;
        for(vector<int> edge: edges){
            mp[edge[0]]++;
            mp[edge[1]]++;
        }
        for(auto m: mp){
            if(m.second == n){
                return m.first;
            }
        }
        return -1;
    }
};