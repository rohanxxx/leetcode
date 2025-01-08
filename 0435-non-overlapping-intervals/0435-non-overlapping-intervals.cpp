
bool compareY(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareY);
        int maxRange = INT_MIN;
        int removeOperations = 0;
        for(auto i: intervals){
            int x = i[0];
            int y = i[1];
            if(x >= maxRange) maxRange = y;
            else removeOperations++;
        }
        return removeOperations;
    }
};