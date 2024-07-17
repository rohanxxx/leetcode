class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int ROWS = mat.size();
        int COLS = mat[0].size();


        unordered_map<int, pair<int, int>> mp;
        
        for(int r = 0; r < ROWS; r++)
            for(int c = 0; c < COLS; c++) mp[mat[r][c]] = {r, c};

        vector<int> row(ROWS, 0);
        vector<int> column(COLS, 0);

        for(int i = 0; i < arr.size(); i++){
            if(mp.find(arr[i]) != mp.end()){
                int r = mp[arr[i]].first;
                int c = mp[arr[i]].second;
                
                //mark the row
                row[r]++;
                if(row[r] == COLS) return i;
                //mark the column
                column[c]++;
                if(column[c] == ROWS) return i;
            }
        }

        return -1;
    }
};