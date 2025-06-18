/*
    [1,4] duration = 5
    1 -> 1+5-1 = 5
    4 -> 4+5-1 = 8?
    total should be here 8 seconds?

    prevEnd = 5
    but start = 4.       5
    if(start <= 5) totalSecond -= (5-4-1)
*/
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int prevEnd = -1;
        int totalSecond = 0;
        //TC: O(N)
        //SC: O(1)
        for(auto& start: timeSeries){
            if(start <= prevEnd){
                totalSecond -= (prevEnd - start + 1);
            }
            prevEnd = (start+duration-1);
            totalSecond += duration;
        }
        return totalSecond;
    }
};