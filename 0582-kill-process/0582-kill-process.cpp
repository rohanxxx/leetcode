class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        int n = ppid.size();
        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < n; i++){
            graph[ppid[i]].push_back(pid[i]);
        }

        vector<int> ans;
        queue<int> q; q.push(kill);
        while(!q.empty()){
            int k = q.front(); q.pop();
            ans.push_back(k);
            int size = graph[k].size();
            for(int i = 0; i < size; i++){
                q.push(graph[k][i]);
            }
        }

        return ans;
    }
};