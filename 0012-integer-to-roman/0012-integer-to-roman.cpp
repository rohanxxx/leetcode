class Solution {
public:
    string intToRoman(int num) {
        vector<int> value = {
            1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1
        };
        vector<string> romanSymbol = {
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"
        };

        string ans = "";
        for(int i = 0; i < value.size(); i++){
            while(num >= value[i]){
                num -= value[i];
                ans += romanSymbol[i];
            }
        }
        return ans;
    }
};