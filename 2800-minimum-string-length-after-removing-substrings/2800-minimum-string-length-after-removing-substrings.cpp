class Solution {
public:
    int minLength(string s) {
        stack<char> stack;
        for(char c: s){
            stack.push(c);
            if(stack.top() == 'B') {
                stack.pop();
                if(!stack.empty() && stack.top() == 'A') stack.pop();
                else stack.push('B');
            }
            else{
                if(stack.top() == 'D'){
                    stack.pop();
                    if(!stack.empty() && stack.top() == 'C') stack.pop();
                    else stack.push('D');
                }
            }
        }
        return stack.size();
    }
};