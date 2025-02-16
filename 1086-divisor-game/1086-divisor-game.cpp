class Solution {
public:
    bool divisorGame(int n) {
        int winner = 0;
        while (n != 1) {
            winner += 1;
            n -= 1;
        }

        if (winner % 2 == 0) {
            return false;
        } else {
            return true;
        }
    }
};

/*
Intuition
On each players's turn, the x must be equal to 1 (x=1).

Approach
winner=0variable indicates the players : Alice and Bob.
On each players's turn, the x must be equal to 1. So, n = n-x is equal to n = n-1 and n%x==0 must be True.
while loop will iterate till n!=1 because (0 < x < n) and if n==1 then there will be no possible value for x .
Alice will start playing first. So, when winner evaluates to an odd number the winner will be Alice.
Similarly, when winner evaluates to an even number the winner will be Bob.
Complexity
Time complexity: O(1)
Space complexity: O(1)
*/