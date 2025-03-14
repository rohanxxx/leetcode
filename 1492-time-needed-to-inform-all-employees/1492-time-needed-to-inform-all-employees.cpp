class Solution {
public:
    int maxTime = INT_MIN;
    void dfs(unordered_map<int, vector<int>>& graph, vector<int>& informTime, int currentID, int time){
        maxTime = max(maxTime, time);
        for(int id: graph[currentID]){
            dfs(graph, informTime, id, time+informTime[id]);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < n; i++){
            if(manager[i] == -1) continue;
            graph[manager[i]].push_back(i);
        }
        maxTime = informTime[headID];
        dfs(graph, informTime, headID, maxTime);
        return maxTime;
    }
};