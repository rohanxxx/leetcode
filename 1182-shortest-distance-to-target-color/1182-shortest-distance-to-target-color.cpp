/*  
              0 1 2 3 4 5 6 7 8
    colors = [1,1,2,1,3,2,2,3,3], queries = [[1,3],[2,2],[6,1]]
    ans => 4-1-> {3, 0, 3}

    1 -> 0,1,3
    2 -> 2,5,6
    3 -> 4,7,8
    min(4-1->3, 9-3 -> 6)
    min(2-2->0, 9-0 -> 9)
    min()

    create hashmap of colors with their indexes
*/
class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();

        vector<int> rightmost = {0, 0, 0};
        vector<int> leftmost = {n - 1, n - 1, n - 1};

        vector<vector<int>> distance(3, vector<int>(n, -1));

        // looking forward
        for(int i = 0; i < n; i++){
            int color = colors[i] - 1;

            for(int j = rightmost[color]; j < i + 1; j++){
                distance[color][j] = i - j;
            }

            rightmost[color] = i + 1;
        }

        // looking backward
        for(int i = n - 1; i >= 0; i--){
            int color = colors[i] - 1;

            for(int j = leftmost[color]; j > i - 1; j--){
                if(distance[color][j] == -1 || distance[color][j] > j - i){
                    distance[color][j] = j - i;
                }
            }

            leftmost[color] = i - 1;
        }

        vector<int> queryResults;

        for(int i = 0; i < queries.size(); i++){
            int idx = queries[i][0];
            int color = queries[i][1] - 1;

            queryResults.push_back(distance[color][idx]);
        }

        return queryResults;
    }
};