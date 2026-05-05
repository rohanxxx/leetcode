/*
        Input: roads = [[3,1],[3,2],[1,0],[0,4],[0,5],[4,6]], seats = 2
        Output: 7

                        0 - 1 - 3 
                        |\        \
                        4 5        2
                        |
                        6
*/
class Solution {
public:
    vector<long long> dfs(int node, int parent, unordered_map<int, vector<int>>& tree, int& k, long long& minCost){
        long long pathCount = 1;
        long long seatCount = 1;
        long long neighborPathCount = 0;
        for(auto adj: tree[node]){
            if(adj == parent) continue;  // don't recurse back up
            vector<long long> res = dfs(adj, node, tree, k, minCost);
            neighborPathCount += res[0];
            seatCount += res[1];
        }

        if(node == 0){
            minCost = neighborPathCount;
        }

        long long carCount = (long long)ceil((double)seatCount/k);
        long long newCost = neighborPathCount + pathCount * carCount;
        return {newCost, seatCount};
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        unordered_map<int, vector<int>> tree;
        for(auto it: roads){
            tree[it[0]].push_back(it[1]);
            tree[it[1]].push_back(it[0]);
        }

        long long minCost = 0;
        dfs(0, -1, tree, seats, minCost);  // pass -1 as initial parent
        return minCost;
    }
};