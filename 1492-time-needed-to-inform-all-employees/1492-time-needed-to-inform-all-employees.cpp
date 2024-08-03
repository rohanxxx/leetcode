class Solution {
public:
    int maxTime = INT_MIN;
    void dfs(unordered_map<int, vector<int>>& mp, vector<int>& informTime, int currentID, int totalTime){
        maxTime = max(maxTime, totalTime);
        for(auto& id: mp[currentID]){
            dfs(mp, informTime, id, totalTime+informTime[id]);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < manager.size(); i++){
            if(manager[i] == -1) continue;
            mp[manager[i]].push_back(i);
        }
        dfs(mp, informTime, headID, informTime[headID]);
        return maxTime;
    }
};