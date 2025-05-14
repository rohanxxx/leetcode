/*
    int n 
    int threshold
    graph: 0 -> n-1
    edges = = [Ai, Bi, Wi] 

    node 0 must reachable from all other nodes
    maximum edge weight in the resulting graph is minimized
    each node has at most threshold outgoing edges

    Return the minimum possible value of the maximum edge weight after removing the necessary edges. 
    If it is impossible for all conditions to  be satisfied, return -1.


    0 1 2 3 4 5 6 
    
    Input: n = 5, edges = [[1,0,1],[2,0,2],[3,0,1],[4,3,1],[2,1,1]], threshold = 2
    Output: 1
                             1
                           3 <- 4
                         1  \  2
                             0 <- 2
                          1  |  / 1
                              1
    after doing prim's algorithm 

    Input: n = 5, 
    edges = [[0,1,1],[0,2,2],[0,3,1],[0,4,1],[1,2,1],[1,4,1]], 
    threshold = 1

          3.  2
         /./. |
         0 -> 1
         \
          4


class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        //reverse the edges
        //create the graph

        //apply prim's algorithm using minHeap queue
        //in the process we will keep track of the maxEdge weights that doesn't cross the threshold

        //lastly we will make a run of our distance vector if it's over threshold from 0 to that particular node
        //we return -1 because it is not connected
    }
};
*/
class Solution {
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        int mn=0;
        vector<int>vis(n);
        vector<vector<vector<int>>>invg(n);
        for(auto i:edges){
            invg[i[1]].push_back({i[2],i[0]}); // reversing the edges 
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq; // to get lower weight edge first
        pq.push({0,0});
        while(pq.size()){
            auto node=pq.top()[1],w=pq.top()[0];
            pq.pop();
            if(vis[node])continue;
            vis[node]=1;
            mn=max(mn,w); // geting the biggest weight edge till now 
            for(auto i:invg[node]){
                if(!vis[i[1]])
                pq.push(i);
            }
        }
        for(auto i:vis)if(i==0)return -1; // if any node is just unreachble then return -1 
        return mn;  
    }
};