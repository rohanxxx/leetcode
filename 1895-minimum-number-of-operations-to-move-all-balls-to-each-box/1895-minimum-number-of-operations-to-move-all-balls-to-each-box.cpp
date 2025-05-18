/*
    i is adj to box j if abs(i-j) == 1

    i = 3
    j = 4,2

    0 1 2 3 4 5 6 7 8
    Input: boxes = "110"
    Output: [1,1,3]
     0 1 2
    "1 1 0"
    count += i-j
    i = 0 ->    

    sum-oneCunt+1
    1 + 1    
      0 1 2 3 4 5 6 7 8  9  10
     [0,0,1,0,1,0,1,1,0, 0, 1]
      0 0 0 1
     [0,0,0,1,2,3,6,9,13,17,21]

*/
class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0), answer2(n,0), answer3(n,0);
        int ballsToLeft = 0, movesToLeft = 0;
        int ballsToRight = 0, movesToRight = 0;

        // Single pass: calculate moves from both left and right
        for (int i = 0; i < n; i++) {
            // Left pass
            answer[i] += movesToLeft;
            ballsToLeft += boxes[i] - '0';
            movesToLeft += ballsToLeft;

            // Right pass
            int j = n - 1 - i;
            answer[j] += movesToRight;
            ballsToRight += boxes[j] - '0';
            movesToRight += ballsToRight;
        }

        return answer;
    }
};