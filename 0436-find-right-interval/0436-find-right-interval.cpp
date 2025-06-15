/*

    intervals = [[3,4],[2,3],[1,2]] -> -1, 0, 1
    [1,2] [2,3] [3,4] 

    1,2 -> 2 x
    2,3 -> 1
    3,4 -> 0
                                         0 1 2
    1,2 then check pq.top().startj >= 2 {-1,0,1}

    Input: intervals = [[1,4],[2,3],[3,4]]
    Output: [-1,2,-1]


    that maps index 1
    1->0
    2->1
    3->2

    4 -> 0;
    3 -> 1;
    4 -> 2
*/

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<int> ans, temp;
        unordered_map<int, int> map;

        int n = intervals.size();
        for(int i = 0; i < n; i++){
            temp.push_back(intervals[i][0]);
            map[intervals[i][0]] = i;
        }
        temp.push_back(INT_MAX);
        map[INT_MAX] = -1;
        sort(temp.begin(), temp.end());

        for(int i = 0; i < n; i++){
            int index = lower_bound(temp.begin(), temp.end(), intervals[i][1]) - temp.begin();
            int val = temp[index];
            ans.push_back(map[val]);
        }

        return ans;
    }
};