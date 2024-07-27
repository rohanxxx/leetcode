class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxAltitude = 0;
        int altitudeSum = 0;
        for(int i = 0; i < gain.size(); i++){
            altitudeSum += gain[i];
            maxAltitude = max(maxAltitude, altitudeSum);
        }
        return maxAltitude;
    }
};