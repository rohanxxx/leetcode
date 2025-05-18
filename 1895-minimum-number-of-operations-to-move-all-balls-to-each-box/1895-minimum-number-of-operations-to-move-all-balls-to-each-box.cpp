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
        vector<int> answer(boxes.length());
        for (int currentBox = 0; currentBox < boxes.length(); currentBox++) {
            // If the current box contains a ball, calculate the number of moves
            // for every box.
            if (boxes[currentBox] == '1') {
                for (int newPosition = 0; newPosition < boxes.length();
                     newPosition++) {
                    answer[newPosition] += abs(newPosition - currentBox);
                }
            }
        }
        return answer;
    }
};