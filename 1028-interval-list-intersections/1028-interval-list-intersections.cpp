/*
    Input: firstList = [[0,2],[5,10],[13,23],[24,25]], secondList = [[1,5],[8,12],[15,24],[25,26]]
    Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
    firstList =  [[0,2],[5,10],[13,23],[24,25]]
    secondList = [[1,5],[8,12],[15,24],[25,26]]
    Output: [[1,2],[5,5],[8,10],[15,23],[24,24],[25,25]]
*/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i = 0, j = 0;
        while(i < firstList.size() && j < secondList.size()){
            int lo = max(firstList[i][0], secondList[j][0]);
            int hi = min(firstList[i][1], secondList[j][1]);
            if(lo <= hi){
                ans.push_back({lo, hi});
            }
            if(firstList[i][1] < secondList[j][1]) i++;
            else j++;
        }
        return ans;
    }
};