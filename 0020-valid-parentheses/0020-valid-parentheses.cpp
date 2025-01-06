class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for(char c: s){
            if(!stack.empty()){
                if(c == ')' || c == '}' || c == ']'){
                    if((stack.top() == '(' && c == ')') || (stack.top() == '{' && c == '}') || (stack.top() == '[' && c == ']')){
                        stack.pop();
                    }
                    else return false;
                    continue;
                }
            }
            stack.push(c);
        }
        if(stack.empty()) return true;
        return false;
    }
};