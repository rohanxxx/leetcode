class Solution {
public:
    //TC: O(NlogN + N)
    //SC: O(N)
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //TC: O(NLogN)
        //SC: O(N)
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> mergedPairs;

        //TC: O(N)
        for(auto it: intervals){
            if(mergedPairs.empty()){
                mergedPairs.push_back({it[0], it[1]});
                continue;
            }
            if(mergedPairs.back()[1] >= it[0]){
                mergedPairs.back()[1] = max(it[1], mergedPairs.back()[1]);
            }
            else{
                mergedPairs.push_back({it[0], it[1]});
            }
        }

        return mergedPairs;
    }
};