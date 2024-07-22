bool compareY(vector<int>& a, vector<int>& b){
    return a[1] < b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareY);
        // sort(intervals.begin(), intervals.end());
        for(auto& i: intervals){
            cout << "[" << i[0] << "," << i[1] << "],";
        }
        cout << "]"<< endl;
        int maxRange = INT_MIN;
        int removeOperations = 0;
        for(auto interval: intervals){
            int x = interval[0];
            int y = interval[1];
            if(x >= maxRange) maxRange = y;
            else removeOperations++;
        }
        return removeOperations;
    }
};