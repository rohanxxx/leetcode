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
        vector<vector<int>> map(4);

        int n = colors.size();
        for(int i = 0; i < n; i++){
            map[colors[i]].push_back(i);
        }

        vector<int> ans;

        for(auto q: queries){
            int i = q[0];
            int target = q[1];
            
            if(map[target].empty()){
                ans.push_back(-1);
                continue;
            }

            auto it = lower_bound(map[target].begin(), map[target].end(), i);
            int index = it - map[target].begin();

            int best = INT_MAX;

            // "end" case (keep continue)
            if(index == map[target].size()){
                int j = map[target][index-1];
                best = min(best, abs(j - i));
                ans.push_back(best);
                continue;
            }

            // normal case
            int j = map[target][index];
            best = min(best, abs(j - i));

            if(index - 1 >= 0){
                int j = map[target][index - 1];
                best = min(best, abs(j - i));
            }

            ans.push_back(best);
        }

        return ans;
    }
};