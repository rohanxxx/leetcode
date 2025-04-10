class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int>> minQue;
        int roomsRequired = 0;
        for(auto interval: intervals){
            if(!minQue.empty()){
                if(minQue.top() <= interval[0]) minQue.pop();
            }
            minQue.push(interval[1]);
            roomsRequired = max((int)minQue.size(), roomsRequired);
        }

        return roomsRequired;
    }
};