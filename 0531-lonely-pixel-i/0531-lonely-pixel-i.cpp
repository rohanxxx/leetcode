class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {

        int n = picture.size();
        int m = picture[0].size();

        unordered_map<int, unordered_set<int>> row;
        unordered_map<int, unordered_set<int>> column;

        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(picture[r][c] == 'B'){
                    row[r].insert(c);
                    column[c].insert(r);
                }
            }
        }

        int lonelyPixel = 0;
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(picture[r][c] == 'B'){
                    if(row[r].size() == 1 && column[c].size() == 1) lonelyPixel++;
                }
            }
        }

        return lonelyPixel;
    }
};