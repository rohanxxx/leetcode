/*
    node u is target to v
    if the number of edges on the path from u to v is less than or equal to k
    then the node is always target to itself

    return an array n integers of answer, where answer[i] is the maximum number of nodes target to node i of the
    first tree if you have to connect one node from the first tree to another node in the second tree

      0
     / \
    1.  2
       / \ 
      3.  4
      
      0 - 3
     / \
    1.  2 
     \    \
      4    7
     / \
    5.  6   

*/
class Solution {
public:
    int bfs(int node, unordered_map<int, vector<int>>& graph, int k){
        int nCount = 0;
        int n = graph.size()+1;
        vector<int> visited(n, 0);
        queue<vector<int>> q;
        //{kCount, node}
        q.push({0, node});
        visited[node] = 1;
        while(!q.empty()){
            int curNode = q.front()[1];
            int kCount = q.front()[0];
            q.pop();
            for(auto adjn: graph[curNode]){
                if(visited[adjn] == 0){
                    if(kCount+1 <= k){
                        q.push({kCount+1, adjn});
                        visited[adjn] = 1;
                        nCount++;
                    }
                }
            }
        }
        return nCount;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        vector<int> ans (n, 0);
        vector<int> tree1Map (n, 0);
        vector<int> tree2Map (m, 0);
        unordered_map<int, vector<int>> graph1;
        unordered_map<int, vector<int>> graph2;
        for(auto node: edges1){
            graph1[node[0]].push_back(node[1]);
            graph1[node[1]].push_back(node[0]);
        }
        for(auto node: edges2){
            graph2[node[0]].push_back(node[1]);
            graph2[node[1]].push_back(node[0]);
        }
        for(int i = 0; i < n; i++){
            tree1Map[i] = bfs(i, graph1, k);
            cout << "i: " << i << " tree1Map: " << tree1Map[i] << endl;
        }
        int adjnCount = 0;
        for(int i = 0; i < m; i++){
            tree2Map[i] = bfs(i, graph2, k-1);
            adjnCount = max(adjnCount, tree2Map[i]);
        }
        for(int i = 0; i < n; i++){
            //cout 
            ans[i] = tree1Map[i];
            if(k > 0){
                ans[i] += (adjnCount + 2);
            }
            if(ans[i] == 0){
                ans[i] = 1;
            }
        }
        return ans;
    }
};