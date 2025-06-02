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
    int bfs(vector<vector<int>>& r1,int k, int i, int n){
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(i);
        int dist = 0;
        int cnt = 0;
        visited[i] = true;
        while(!q.empty() && dist <= k){
            int n1 = q.size();
            while(n1--){
                int temp = q.front();
                q.pop();
                cnt++;
                for(int v: r1[temp]){
                    if(!visited[v]){
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            dist++;
        }
        return cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size();
        int m = edges2.size();
        vector<vector<int>>r1(n+1,vector<int>()),r2(m+1,vector<int>());
        for(vector<int>&ans : edges1){
            r1[ans[0]].push_back(ans[1]);
            r1[ans[1]].push_back(ans[0]);
        }
        for(vector<int>&ans : edges2){
            r2[ans[0]].push_back(ans[1]);
            r2[ans[1]].push_back(ans[0]);
        }
        vector<int>curr(n+1);
        for(int i=0;i<=n;i++){
            curr[i] = bfs(r1,k,i,n+1);
        }
        int dc = 0;
        for(int i=0;i<=m;i++){
            dc = max(dc,bfs(r2,k-1,i,m+1));
        }
        vector<int>ans;
        for(int i=0;i<=n;i++){
            ans.push_back(curr[i]+dc);
        }
        return ans;
    }
};