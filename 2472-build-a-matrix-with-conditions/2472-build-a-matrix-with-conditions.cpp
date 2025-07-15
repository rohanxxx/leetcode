class Solution {
public:
    //build topoSort
    void topoSort(queue<int>& q, vector<int>& topoSort, vector<int>& indegree, vector<vector<int>>& graph){
        while(!q.empty()){
            int node = q.front(); q.pop();
            topoSort.push_back(node);
            for(auto& adjn: graph[node]){
                if(--indegree[adjn] == 0){
                    q.push(adjn);
                }
            }
        }
        return;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> rowGraph(k+1), colGraph(k+1);
        vector<int> rowIndegree(k+1), colIndegree(k+1);
        //TC:O(K+K)
        //build the graph
        //TC: O(N+E)
        for(vector<int>& pair: rowConditions){
            int u = pair[0];
            int v = pair[1];
            rowGraph[u].push_back(v);
            rowIndegree[v]++;
        }
        for(vector<int>& pair: colConditions){
            int u = pair[0];
            int v = pair[1];
            colGraph[u].push_back(v);
            colIndegree[v]++;
        }

        queue<int> rowQ, colQ;
        //TC: O(N)
        //building the indegrees of row and col graph
        for(int i = 1; i <= k; i++){
            if(rowIndegree[i] == 0){
                rowQ.push(i);
            }
        }
        for(int i = 1; i <= k; i++){
            if(colIndegree[i] == 0){
                colQ.push(i);
            }
        }
        
        vector<int> rowTopoSort, colTopoSort;

        topoSort(rowQ, rowTopoSort, rowIndegree, rowGraph);
        topoSort(colQ, colTopoSort, colIndegree, colGraph);

        if(rowTopoSort.size() != k) return {};
        if(colTopoSort.size() != k) return {};

        unordered_map<int, int> rowMap, colMap;
        for (int i = 0; i < k; i++) {
            rowMap[rowTopoSort[i]] = i;
            colMap[colTopoSort[i]] = i;
        }

        vector<vector<int>> matrix (k, vector<int>(k, 0));
        for(int i = 1; i <= k; i++){
            int matrixRow = rowMap[i];
            int matrixCol = colMap[i];
            matrix[matrixRow][matrixCol] = i;
        }

        return matrix;
    }
};