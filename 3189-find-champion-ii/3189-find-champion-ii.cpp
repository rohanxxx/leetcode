class Solution {
public:
    //Total TC: O(N+E)
    //Total SC: O(N)
    int findChampion(int n, vector<vector<int>>& edges) {
        //SC: O(N)
        vector<int> indegree(n);
        //O(E)
        for(auto it: edges){
            indegree[it[1]]++;
        }

        int champion = -1;
        int championCount = 0;
        //O(N)
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                champion = i;
                championCount++;
            }
        }
        
        //O(1)
        if(championCount == 1){
            return champion;
        }

        return -1;
    }
};