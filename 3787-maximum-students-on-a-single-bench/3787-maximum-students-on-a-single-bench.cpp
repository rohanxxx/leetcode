class Solution {
public:
    int maxStudentsOnBench(vector<vector<int>>& students) {
        unordered_map<int, unordered_set<int>> mp;
        for(vector<int> v: students){
            mp[v[1]].insert(v[0]);
        }

        int maxUnique = 0;
        for(auto bench: mp){
            maxUnique = max(maxUnique, (int)bench.second.size());
        }
        return maxUnique;
    }
};