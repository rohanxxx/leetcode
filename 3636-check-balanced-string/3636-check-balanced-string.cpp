class Solution {
public:
    bool isBalanced(string num) {
        int oddSum = 0, evenSum = 0;
        for(int i = 0; i < num.length(); i++){
            int digit = (num[i]-'0');
            if(i%2){
                oddSum += digit;
                continue;
            }
            evenSum += digit;
        }

        if(evenSum == oddSum){
            return true;
        }

        return false;
    }
};