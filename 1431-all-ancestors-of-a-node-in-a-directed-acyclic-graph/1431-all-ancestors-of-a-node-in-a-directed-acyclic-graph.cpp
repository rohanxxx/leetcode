/*
    1) Directed Acyclic graph
    2) n is the node number 0 -> n-1
    3) edges[i] = [fromi, toi]

      0 1. .2.  3.    4.     5.       6.         7
    [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
    Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]

    1 0 2
     \|\|\
      3 4 7
      |\|
      5 6
*/
class Solution {
public:
    //O(N^2*M)
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        //first do indegree count
        //generate the graph
        vector<int> visited(n, 0);
        vector<int> indegree(n, 0);
        vector<vector<int>> graph(n);
        for(auto& it: edges){
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            indegree[v]++;
        }
        
        //O(N*M)
        vector<set<int>> temp_ans(n);
        //ancestors that has no parent and we push it to the queue
        //pair<node, parent>
        queue<pair<int, int>> q;
        //O(N)
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                visited[i] = 1;
                q.push({i, -1});
            }
        }

        //then do bfs keeping track of parent
        //each traversal we use the adjNode parents and insert it the temp ans
        //O(N^2 + E)
        while(!q.empty()){
            int curNode = q.front().first;
            int parentNode = q.front().second;
            q.pop();
            //check the indegree is 0
            //before checking that we will put the adjNode nodes parents to temp[adjNode]
            for(auto adjNode: graph[curNode]){
                if(temp_ans[curNode].size() > 0){
                    for(auto it: temp_ans[curNode]){
                        temp_ans[adjNode].insert(it);
                    }
                }
                temp_ans[adjNode].insert(curNode);
                if(visited[adjNode] == 0){
                    if(--indegree[adjNode] == 0){
                        visited[adjNode] = 1;
                        q.push({adjNode, curNode});
                    }
                }
            }
        }

        vector<vector<int>> ans(n);
        //O(N*M)
        for(int i = 0; i < n; i++){
            for(auto& it: temp_ans[i]){
                ans[i].push_back(it);
            }
        }

        return ans;
    }
};