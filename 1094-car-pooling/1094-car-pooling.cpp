/*
    trips = [[2,1,5],[3,3,7]], capacity = 5

    0 1 2 3 4  5 6 7
        2 3   -2.  3
        2 5 5  3 3 3
    
    trips = [[2,1,5],[3,3,7]], capacity = 4

    1 2 3 4  5 6 7
    2.  3   -2.  3
    curr -> 0 -> 2 -> 5 ->
    (5,2) 

    O(NlogN)
    sort(trips.begin(), trips.end(), comp);

    minHeap;
    O(NlogN)
    count = 0;
    for(auto it: trips){
        
    }

    [[9,0,1],[3,3,7]]

    0 1 
*/
class Solution {
public:
    //TC: O(N+MAX(Time))
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> bucket(1000+1,0);
        int minTime = INT_MAX, maxTime = INT_MIN;

        //TC: O(N)
        for(auto it: trips){
            int pass = it[0];
            int t1 = it[1];
            int t2 = it[2];
            bucket[t1] += pass;
            bucket[t2] -= pass;

            minTime = min(t1, minTime);
            maxTime = max(t2, maxTime);
        }

        int curr = 0;
        //TC: O(max(time))
        for(int t = minTime; t <= maxTime; t++){
            curr += bucket[t];
            if(curr > capacity){
                return false;
            }
        }

        return true;
    }
};