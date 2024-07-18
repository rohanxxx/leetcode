class Solution {
public:
    string getSmallestString(string s) {
        for(int i = 1; i < s.length(); i++){
            int digit1 = s[i] - '0';
            int digit2 = s[i-1] - '0';
            
            if(digit1%2 == digit2%2 && digit1 < digit2){
                swap(s[i], s[i-1]);
                break;
            }
        }
        return s;
    }
};