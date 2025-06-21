/*
    Input: s = "IceCreAm"
    Output: "AceCreIm"

    IceCreAm
    
    IeeA
    AeeI
*/
class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "";
        for(auto c: s){
            if(toupper(c) == 'A' || toupper(c) == 'E' || toupper(c) == 'I' || toupper(c) == 'O' || toupper(c) == 'U'){
                vowels += c;
            }
        }

        //reverse(vowels)
        int ptr = vowels.size()-1;
        for(auto& c: s){
            if(toupper(c) == 'A' || toupper(c) == 'E' || toupper(c) == 'I' || toupper(c) == 'O' || toupper(c) == 'U'){
                c = vowels[ptr];
                ptr--;
            }
            if(ptr < 0) break;
        }

        return s;
    }
};