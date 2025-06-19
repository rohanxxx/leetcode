/*
    for example when 
    n = 0 we have 0 choices
    n = 1 we have 10 unique from 0-9
    n = 2 the total choices are from 0 to 99 100 options
    for n = 1 10 unique + 9X9 = 81
    n = 3 10 + 9*9 + 9*9*8
*/
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;

        int count = 10;
        //TC: O(64)
        //SC: O(1)
        for(int i = 2; i <= n; i++){
            int x = 9;
            int available = 9;
            for (int j = 1; j <= i - 1; j++) {
                x *= available;
                available--;
            }
            count += x;
            //count += x;
        }

        return count;
    }
};