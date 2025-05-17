/*
    60 * 20 = 1200 
    60 * 3 = 180
    totalTime = 1380 minutes + 59 minutes => 1439 minutes

    24 hour = 1440 minutes

    0 minutes

    Input: timePoints = ["23:59","00:00"]
    Output: 1

    [0, 1439] -> 1 minutes
    [49, 1439] -> 49 minutes
    (49+1440 - 1439) 
    1220, 1440 -> 220 minutes
    1220 + 1440 - 1440 - 1220 minutes

    [49, 1439]

    min((abs(49+1440 - 1439), abs(49-1439))

    first we convert the timeList to minutes and push_back to a vector //nlogn

    then sort() //nlogn

    O(n)
    for(int i = 1 -> n){

    }

    01234
    hh:mm
    23:49
    {0, 10, 20, 30, 60, 1439}
*/
class Solution {
public:
    //O(N*K*logN)
    int findMinDifference(vector<string>& timePoints) {
        /*first we convert the timeList to minutes and push_back to a vector //nlogn*/
        //SC: O(N)
        vector<int> minutesV;
        //TC(N*K)
        for(auto& s: timePoints){
            int hourToMinute = 60*stoi(s.substr(0, 2));
            int minutes = stoi(s.substr(3, 2)); //TC: O(K)
            minutes += hourToMinute;
            minutesV.push_back(minutes); //TC: O(1)
        }

        //O(Nlog(N))
        sort(minutesV.begin(), minutesV.end());

        int n = minutesV.size();
        int minTimeDif = INT_MAX;
        //O(N)
        //find the min time difference
        for(int i = 1; i < n; i++){
            //TC: O(1)
            //min((abs(49+1440 - 1439), abs(49-1439))
            minTimeDif = min({minTimeDif, abs(minutesV[i-1]+1440-minutesV[i]), abs(minutesV[i-1]-minutesV[i])});
        }

        //TC: O(1)
        //at the end check the last element with the first one
        minTimeDif = min({minTimeDif, abs(minutesV[0]+1440-minutesV[n-1]), abs(minutesV[0]-minutesV[n-1])});
        if(minTimeDif == INT_MAX){
            return -1;
        }
        return minTimeDif;
    }
};