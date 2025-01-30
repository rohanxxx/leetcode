class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        if(s.length() < numRows) return s;

        int maxJump = (numRows-2)+numRows;
        int j1 = maxJump;
        int j2 = 0;

        string ans = "";
        for(int i = 0; i < numRows; i++){
            int index = i;
            ans += s[index];
            while(j1 >= 0 && j2 <= maxJump){
                if(j1){
                    index += j1;
                    if(index > s.length()-1) break;
                    ans += s[index];
                }
                if(j2){
                    index += j2;
                    if(index > s.length()-1) break;
                    ans += s[index];
                }
            }

            j1 -= 2;
            j2 += 2;
        }

        return ans;
    }
};