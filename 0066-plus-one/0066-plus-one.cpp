/*
    1999
    9999
*/
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() -1;
        int holder = 0;
        for(int i = n; i >= 0; i--){
            if(digits[i] == 9){
                digits[i] = 0;
                holder = 1;
                continue;
            }

            holder = 0;
            digits[i]++;
            break;
        }

        if(holder == 1){
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};