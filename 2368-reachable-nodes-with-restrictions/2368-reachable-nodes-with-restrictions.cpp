/*
     start node 0 always unrestricted
     avoid restricted node
     visit maximum #'s  of node avoiding restricted node

     n = 7, edges = [[0,1],[1,2],[3,1],[4,0],[0,5],[5,6]], restricted = [4,5]
    
        5 - 6
      / 
     0 - 1 - 2
     |    \ 
     4     3

     restricted node = 4,5
*/
class Solution {
public:
    //TC: O(V+E+M)
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        //first step
        //build the undirected tree
        //TC: O(V)
        vector<vector<int>> tree(n);
        //TC: O(E)
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        //TC: O(M)
        unordered_set<int> restrictedSet(restricted.begin(), restricted.end());

        queue<pair<int, int>> q;
        vector<int> visited(n, 0);

        q.push({0, -1});
        visited[0] = 1; //marks visited

        int count = 0;
        //O(E+V)
        while(!q.empty()){
            auto it = q.front(); q.pop();
            int node = it.first;
            int parent = it.second;

            count++;

            for(auto adj: tree[node]){
                if(adj == parent || visited[adj] == 1){
                    continue;
                }
                //check if it's restricted
                //then skip
                //TC: O(1)
                if(restrictedSet.find(adj) != restrictedSet.end()){
                    continue;
                }
                //otherwise it's valid
                q.push({adj, node});
                visited[adj] = 1; //marks visited
            }
        }

        return count;
    }
};