class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i, n = digits.size()-1;
        for(i = n; i >= 0; i--){
            if(digits[i] != 9){
                // digits[i]++;
                break;
            }
            else digits[i] = 0;
        }
        if(i >= 0){
            digits[i]++;
        }
        if(i == -1 && digits[0] == 0){
            digits[0]++;
            digits.push_back(0);
        }
        return digits;
    }
};