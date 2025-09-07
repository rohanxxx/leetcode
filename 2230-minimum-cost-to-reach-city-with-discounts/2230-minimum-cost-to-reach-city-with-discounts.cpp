/*
    Input: n = 5, highways = [[0,1,4],[2,1,3],[1,4,11],[3,2,3],[3,4,2]], discounts = 1
    Output: 9
       4      3      3
    0 ---- 1 ---- 2 ---- 3 
           |            /
           | 11        / 2
           |          /
           4 ---------

    discounts = 1
    return minimum cost from 0 to city 1

*/
class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        vector<vector<pair<int, int>>> graph(n);
        for(auto& it: highways){
            graph[it[0]].push_back({it[1], it[2]});
            graph[it[1]].push_back({it[0], it[2]});
        }

        vector<vector<int>> minCost(n, vector<int>(discounts+1, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        //{curCost, node, parentNode, discountUsedCount}
        minHeap.push({0,0,-1,0});

        //marks the 0th node as 0
        minCost[0][0] = 0;

        while(!minHeap.empty()){
            auto it = minHeap.top(); minHeap.pop();
            
            int curCost = it[0];
            int curNode = it[1];
            int parentNode = it[2];
            int count = it[3];

            //if the solution is found
            if(curNode == n-1){
                return curCost;
            }

            //traverse all the possible path
            for(auto it: graph[curNode]){
                int adjn = it.first;
                int toll = it.second;

                if(adjn == parentNode) continue;

                int newCost = toll + curCost;

                //this is without applying any discounts
                if(newCost < minCost[adjn][count]){
                    minCost[adjn][count] = newCost;
                    minHeap.push({newCost, adjn, curNode, count});
                }

                int newDiscountedCost = curCost;

                //this is with applying the discount
                if(count+1 <= discounts){
                    newDiscountedCost += (int)(toll/2);
                    if(newDiscountedCost < minCost[adjn][count+1]){
                        minCost[adjn][count+1] = newDiscountedCost;
                        minHeap.push({newDiscountedCost, adjn, curNode, count+1});
                    }
                }
            }
        }

        return -1;
    }
};