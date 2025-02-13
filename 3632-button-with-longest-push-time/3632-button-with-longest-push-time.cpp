class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int index = events[0][0];
        int longestTime = events[0][1], n = events.size();
        for(int i = 1; i < n; i++){
            int time = events[i][1]-events[i-1][1];
            if(longestTime <= time){
                if(longestTime == time){
                    index = min(index, events[i][0]);
                    continue;
                }
                longestTime = time;
                index = events[i][0];
            }
        }

        return index;
    }
};