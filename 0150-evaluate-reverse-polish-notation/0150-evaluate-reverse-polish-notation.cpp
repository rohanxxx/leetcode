class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> stack;
        for(string c: tokens){
            if(c == "+" || c == "-" || c == "*" || c == "/"){
                int second = stoi(stack.top()); stack.pop();
                int first = stoi(stack.top()); stack.pop();
                int calculate;
                if(c == "+") calculate = first + second;
                if(c == "-") calculate = first - second;
                if(c == "*") calculate = first * second;
                if(c == "/") calculate = first / second;
                stack.push(to_string(calculate));
                continue;
            }
            stack.push(c);
        }

        return stoi(stack.top());
    }
};