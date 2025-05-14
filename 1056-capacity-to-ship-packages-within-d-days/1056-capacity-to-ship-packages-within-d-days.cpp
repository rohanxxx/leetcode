/*
    I have ith package on the conveyor belth weights[i]
    each day we load the ship with the packages on the conveyor belth (in order given by the weights)

    Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5 total Sum = 55
    Output: 15
               0 1 2  3  4 5 6 7 8 9
    weights = [1,2,3, 4, 5,6,7,8,9,10]
               1 3 6 10 15
*/
class Solution {
public:
    // Check whether the packages can be shipped in less than "days" days with
    // "c" capacity.
    bool feasible(vector<int>& weights, int c, int days) {
        int daysNeeded = 1, currentLoad = 0;
        for (int weight : weights) {
            currentLoad += weight;
            if (currentLoad > c) {
                daysNeeded++;
                currentLoad = weight;
            }
        }

        return daysNeeded <= days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int totalLoad = 0, maxLoad = 0;
        for (int weight : weights) {
            totalLoad += weight;
            maxLoad = max(maxLoad, weight);
        }

        int l = maxLoad, r = totalLoad;
        //cout << "maxLoad: " << maxLoad << endl;
        //cout << "totalLoad: " << totalLoad << endl;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (feasible(weights, mid, days)) {
                r = mid-1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};