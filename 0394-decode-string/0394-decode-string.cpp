class Solution {
public:
    string decodeString(string s) {
        stack<int>countString; 
        stack<string>stringStack;
        string curr_string = "";

        int integer = 0;
        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])){
                integer = integer * 10 + s[i] - '0';
            }
            else if (s[i] == '['){
                countString.push(integer);
                stringStack.push(curr_string);
                
                curr_string = "";
                integer = 0;
            }
            else if (s[i] == ']'){
                int counter = countString.top();
                string decodeString = stringStack.top();

                stringStack.pop();

                for(int counter = countString.top(); counter > 0; counter--){
                    decodeString += curr_string;
                }

                countString.pop();
                curr_string = decodeString;
            }
            else {
                curr_string += s[i];
            }
        }

        return curr_string;
        
    }
};