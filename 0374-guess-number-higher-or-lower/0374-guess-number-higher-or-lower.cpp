/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int lo = 1, hi = n;
        while(lo <= hi){
            int pick = lo + (hi-lo)/2;
            int res = guess(pick);
            if(res == 0) return pick;
            if(res < 0) hi = pick-1;
            else lo = pick+1;
        }
        return -1;
    }
};