class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stack;
        for(auto c: s){
            if(!stack.empty() && stack.top() == '(' && c == ')'){
                stack.pop();
                continue;
            }
            stack.push(c);
        }

        return (int)stack.size();
    }
};