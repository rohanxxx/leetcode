class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(auto it: intervals){
            if(minHeap.empty()){
                minHeap.push(it[1]);
                continue;
            }
            if(it[0] >= minHeap.top()){
                minHeap.pop();
            }
            minHeap.push(it[1]);
        }

        return (int)minHeap.size();
    }
};