class Solution {
public:
    int addDigits(int num) {
        int sum = 0;
        while(num){
            int digit = num%10;
            num /= 10;
            sum += digit;
            // cout << "num: " << num << endl;
            if(num == 0 && sum > 9) {
                num = sum;
                sum = 0;
            }
        }

        return sum;
    }
};