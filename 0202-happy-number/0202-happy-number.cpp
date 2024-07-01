class Solution {
public:
    int newNum(int n){
        int totalSum = 0;
        while(n>0){
            int digit = n%10;
            n = n/10;
            totalSum += (digit*digit);
        }
        return totalSum;
    }
    bool isHappy(int n) {
        unordered_map<int, bool> seen;
        while(n != 1){
            seen[n] = true;
            n = newNum(n);
            if(seen[n] == true) return false;
        }
        return true;
    }
};