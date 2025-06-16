
/*
        0 1 2 3 4 5 6 7 8 9 10 11
        s u b s t i t u t i o  n
        
        0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19
        i n t e r n a t i o n  a  l  i  z  a  t  i  o  n"

        0 1 2 3 4 5 6
        i 1 2 i z 4 n
*/
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int len = word.length();

        int j = 0;
        int integer = 0;
        for(int i = 0; i < abbr.size(); i++){
            cout << "i: " << i << endl;
            if(isdigit(abbr[i])){
                if(abbr[i] == '0' && integer == 0) return false;
                integer = (integer * 10) + (abbr[i] - '0');
            }
            else{
                if(integer > 0) j += integer;
                integer = 0;
                if(j >= len || word[j] != abbr[i]) return false;
                j++;
            }
        }

        j += integer;
        return j == len;
    }
};
