/*
    bloomDay = []
    in order to make m bouquets I need to use k adj flowers from the garden 

    the garden consists of n flowers, ith flower will bloom in the bloomDay[i], then can be used exactly for one
    bouquet

    return the minimum number of days you need to wait to make m bouquets
    otherwise -1

    Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
                       0, 1,2, 3,4
    Output: 3

    Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
                       0,1,2,3, 4,5,6
    Output: 12
*/
class Solution {
public:
    // Return the number of maximum bouquets that can be made on day mid.
    int getNumOfBouquets(vector<int>& bloomDay, int mid, int k) {
        int numOfBouquets = 0;

        int count = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            // If the flower is bloomed, add to the set. Else reset the count.
            if (bloomDay[i] <= mid) {
                count++;
            } else {
                count = 0;
            }

            if (count == k) {
                numOfBouquets++;
                count = 0;
            }
        }

        return numOfBouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int start = 0;
        int end = 0;
        for (int day : bloomDay) {
            end = max(end, day);
        }

        int minDays = -1;
        while (start <= end) {
            int mid = (start + end) / 2;

            if (getNumOfBouquets(bloomDay, mid, k) >= m) {
                minDays = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return minDays;
    }
};