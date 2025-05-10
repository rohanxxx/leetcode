class Solution {
public:
    //overall TC: O(NlogN + MlogM + N+M)
    //overall SC: O(N+M)
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        int ans = -1;
        int ptr = 0;
        int n = passengers.size();
        unordered_set<int> set;
        //TC: O(Nlog(N))
        sort(buses.begin(), buses.end());
        //TC: O(Mlog(M))
        sort(passengers.begin(), passengers.end());
        //TC: O(N+M)
        for(auto bus: buses){
            int capCount = 0;
            while(capCount < capacity && ptr < n && passengers[ptr] <= bus){
                if(set.find(passengers[ptr]-1) == set.end()){
                    ans = passengers[ptr]-1;
                }
                set.insert(passengers[ptr]);
                capCount++; ptr++;
            }

            if(capCount < capacity && set.find(bus) == set.end()){
                ans = bus;
            }
        }
        return ans;
    }
};