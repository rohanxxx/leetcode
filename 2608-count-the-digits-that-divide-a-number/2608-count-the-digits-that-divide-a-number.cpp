/*
    Input: num = 1248
    Output: 4

    copy of num
*/
class Solution {
public:
    int countDigits(int num) {
        int copyNum = num;
        int count = 0;
        while(copyNum){
            int pop = copyNum % 10;
            if(pop != 0 && num % pop == 0){
                count++;
            }
            copyNum = copyNum / 10;
        }
        return count;
    }
};