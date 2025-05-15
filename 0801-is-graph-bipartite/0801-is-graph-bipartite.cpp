/*
graph is undirected
                            0      1    2       3
        Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
        Output: false

        0 - 1
        | \ | 
        3 - 2

        0 - 1
        |   | 
        3 - 2

        0, 0
        pair<nodeValue, mark>
        queue<pair<int, int>>

        q-> (0,0) pop, (1,1)pop, (2,1) (3,1) 

        if(0 is visited) then check if(0 is mapped the opposit of 1's mapping) or else it is false
        else q.push()
*/
class Solution {
public:
    bool bfs(int node, vector<int>& visited, vector<int>& map, vector<vector<int>>& graph){
        queue<pair<int, int>> q;

        //push node 0 to q
        q.push({node, map[node]});
        visited[node] = 1;

        //then do bfs traversal and checking if it bipartite
        //TC: O(N)
        while(!q.empty()){
            int curNode = q.front().first;
            int curMark = q.front().second;
            q.pop();

            for(auto adjNode: graph[curNode]){
                //if not visited
                if(visited[adjNode] == 0){
                    visited[adjNode] = 1;
                    map[adjNode] = (!curMark);
                    q.push({adjNode, !curMark});
                }
                else if(visited[adjNode] == 1 && map[adjNode] == curMark){
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        //declare queue, vector visited, vector<int> map
        int n = graph.size();
        //edge case
        if(n == 0) return true;
        vector<int> visited(n, 0);  //0 means false
        vector<int> map(n, 0);      //initially everything is marked 0
        for(int i = 0; i < n; i++){
            int node = i;
            if(visited[node] == 0){
                visited[node] = 1; //means true
                if(bfs(node, visited, map, graph) == false){
                    return false;
                }
            }
        }

        return true;
    }
};