class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = 0;
        int empty = 0;

        while(numBottles > 0){
            count += numBottles;       // drink all full bottles
            empty += numBottles;       // they become empty
            numBottles = empty / numExchange;   // exchange empties for new full
            empty = empty % numExchange;        // leftover empties carry over
        }

        return count;
        // TC: O(log base numExchange of numBottles)
        // SC: O(1)
    }
};