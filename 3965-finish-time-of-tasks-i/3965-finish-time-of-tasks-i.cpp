/*
    u -> parent of v [u, v]
    basetime represents the time to complete task i

    the finish time of each task is calculated as follows:
    
    * leaf task: the finish time is baseTime[i]
    * Non Leaf task:
        * earliest be the minimum finish time among its children and latest be the maximum finish time among its children
        * let ownDuration be (latest-earliest) + baseTime[i]
        * the finish time of task i is latest+ownDuration

    return the finish task of root 0

                                                     0 1 2
    Input: n = 3, edges = [[0,1],[1,2]], baseTime = [9,5,3]
    Output: 17

    0 -> 1 -> 2
*/
class Solution {
public:
    //O(V+E)
    long long dfs(int node, vector<vector<int>>& graph, vector<int>& baseTime){
        //checking leaf node
        if(graph[node].size() == 0){
            return (long long)baseTime[node];
        }

        //not a leaf node
        //traverse and calculate latest and earliest
        long long earliest = LLONG_MAX, latest = LLONG_MIN;
        //O(E)
        for(auto adj: graph[node]){
            long long ret = dfs(adj, graph, baseTime);
            earliest = (long long)min((long long)earliest, (long long)ret);
            latest = (long long)max((long long)latest, (long long)ret);
        }

        long long ownDuration = (latest-earliest) + baseTime[node];
        return (long long)latest+ ownDuration;
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        vector<vector<int>> graph(n);
        //creates the graph
        //O(E)
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
        }
        //O(V+E)
        return dfs(0, graph, baseTime);
    }
};