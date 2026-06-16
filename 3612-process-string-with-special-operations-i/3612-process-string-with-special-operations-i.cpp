/*
    Input: s = "a#b%*"

    Output: "ba"
     0 1 2 3 4
    "a # b % *"
     a a b
     b a  


*/
class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(auto c: s){
            //append case
            if(c >= 'a' && c <='z'){
                result.push_back(c);
            }
            //remove last c
            if(c == '*'){
                if(!result.empty()){
                    result.pop_back();
                }
            }
            //duplicate the result
            if(c == '#'){
                result = result + result;
            }
            //reverese the current result
            if(c == '%'){
                reverse(result.begin(), result.end());
            }
        }

        return result;
    }
};