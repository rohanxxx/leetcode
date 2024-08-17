class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> incomingEdges(n);
        for(auto& node: edges){
            incomingEdges[node[1]] = true;
        }
        vector<int> requiredNodes;
        for(int i = 0; i < n; i++){
            if(incomingEdges[i] == false){
                requiredNodes.push_back(i);
            }
        }

        return requiredNodes;
    }
};