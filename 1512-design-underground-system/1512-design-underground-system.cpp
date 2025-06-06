/*
 45 - 12
 32 - 14
 27 - 10
*/
class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> timeIn;
    //start, end, avg, count
    unordered_map<string, unordered_map<string, vector<int>>> avgTime;
    
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        timeIn[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string startStation = timeIn[id].first;
        string endStation = stationName;
        int tin = timeIn[id].second, tout = t;
        if(avgTime[startStation][endStation].empty()){
            avgTime[startStation][endStation].push_back(tout-tin);
            avgTime[startStation][endStation].push_back(1);
        }
        else{
            avgTime[startStation][endStation][0] += (tout-tin);
            avgTime[startStation][endStation][1] += 1;
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        return (double)avgTime[startStation][endStation][0] / (double)avgTime[startStation][endStation][1];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */