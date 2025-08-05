/*
    Input: num = 2932
    Output: 52
    0 1 2 3 4
    2 2 3 7 9
    23 29

    239 + 27
    237 + 29
*/
class Solution {
public:
    int minimumSum(int num) {
        vector<int> digits;
        while(num){
            int pop = num % 10;
            digits.push_back(pop);
            num = num/10;
        }

        sort(digits.begin(), digits.end());
        int i = 0, j = 1, n = digits.size();
        int num1 = 0, num2 = 0;
        while(i < n || j < n){
            if(i < n && i % 2 == 0){
                num1 *= 10;
                num1 += digits[i];
                i += 2;
            }
            else{
                if(j < n){
                    num2 *= 10;
                    num2 += digits[j];
                    j += 2;
                }
            }
        }

        return num1 + num2;
    }
};