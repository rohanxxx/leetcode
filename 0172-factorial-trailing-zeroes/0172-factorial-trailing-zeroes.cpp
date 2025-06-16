class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        for(int i = 5; i <= n; i+=5){
            int x = i;
            while(x && x % 5 == 0){
                count++;
                x = x/5;
            }
        }
        return count;
    }
};