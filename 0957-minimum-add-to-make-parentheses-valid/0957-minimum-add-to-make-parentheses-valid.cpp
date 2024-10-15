class Solution {
public:
    int minAddToMakeValid(string s) {
        // int count = 0;
        stack<char> stack;
        for(char c: s){
            if(stack.empty()){
                stack.push(c);
                continue;
            }
            if(stack.top() == '(' && c == ')'){
                stack.pop();
                continue;
            }
            stack.push(c);
        }
        return stack.size();
    }
};