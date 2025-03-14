class Solution {
public:
    int totalTime = 0;
    void dfs(int n, vector<int>& informTime, unordered_map<int, vector<int>>& graph, int currentID, int time){
        totalTime = max(time, totalTime);
        for(int id: graph[currentID]){
            dfs(n, informTime, graph, id, totalTime+informTime[id]);
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < n; i++){
            if(manager[i] == -1) continue;
            graph[manager[i]].push_back(i);
        }
        dfs(n, informTime, graph, headID, informTime[headID]);
        return totalTime;
    }
};