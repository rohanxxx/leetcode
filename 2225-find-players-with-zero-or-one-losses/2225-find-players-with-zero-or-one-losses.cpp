/*
    Input: matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
    
    1 1 0
    2 1 0
    3 1 2
    4 3 1
    5 2 1
    6 0 2
    7 0 1
    8 0 1
    9 0 2
    10 2 0 

    hashmap[key, pair<winCount, loseCount>]
    tc: O(N)
    sc: O(N)
*/
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int, pair<int, int>> map;
        for(auto it: matches){
            int winner = it[0];
            int loser = it[1];
            map[winner].first++;
            map[loser].second++;
        }

        vector<vector<int>> ans(2);
        for(auto it: map){
            int player = it.first;
            pair<int, int> result = it.second;
            if(result.second == 0){
                ans[0].push_back(player);
            }
            if(result.second == 1){
                ans[1].push_back(player);
            }
        }

        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        return ans;
    }
};