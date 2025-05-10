class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        int ans = -1;
        int ptr = 0;
        int n = passengers.size();
        unordered_set<int> set;
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
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