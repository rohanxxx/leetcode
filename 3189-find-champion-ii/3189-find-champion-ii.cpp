class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<bool> inDegreeNodes(n);
        for(auto& edge: edges){
            inDegreeNodes[edge[1]] = true;
        }

        int champion;
        int count = 0;

        for(int i = 0; i < n; i++){
            if(!inDegreeNodes[i]){
                champion = i;
                count++;
            }
        }

        if(count == 1) return champion;
        return -1;
    }
};