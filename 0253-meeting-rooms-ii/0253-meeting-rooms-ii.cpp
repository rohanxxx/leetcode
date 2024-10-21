class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        priority_queue<int, vector<int>, greater<int>> minQue;
        
        for(auto interval: intervals){
            if(!minQue.empty()){
                if(minQue.top() <= interval[0]) minQue.pop();
            }
            minQue.push(interval[1]);
        }

        return minQue.size();
    }
};