class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int singleDigitSum = 0, doubleDigitSum = 0;
        for(int n: nums){
            if(n < 10 && n > -10){
                singleDigitSum += n;
            }
            else{
                doubleDigitSum += n;
            }
        }
        if(singleDigitSum == doubleDigitSum){
            return false;
        }
        return true;
    }
};