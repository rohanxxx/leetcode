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
                cout << "line 14" << endl;
                cout << "i: " << i << endl;
                champion = i;
                count++;
                cout << "count: " << count << endl;
            }
        }

        cout << "line 22 count: " << count << endl;
        cout << "champion: " << champion << endl;
        if(count == 1) return champion;
        return -1;
    }
};