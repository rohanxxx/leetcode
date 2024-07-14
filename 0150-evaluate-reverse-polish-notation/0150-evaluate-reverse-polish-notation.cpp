class Solution {
public:
    int calculate(stack<int> &stack, string sign){
        int first, second;
        second = stack.top(); stack.pop();
        first = stack.top(); stack.pop();

        int new_int = 0;
        if(sign == "+") new_int = first+second;
        if(sign == "-") new_int = first-second;
        if(sign == "*") new_int = first*second;
        if(sign == "/") new_int = first/second;
        
        return new_int;
    }
    int evalRPN(vector<string>& tokens) {
        if(tokens.size() < 2) return stoi(tokens[0]);
        stack<int> stack;
        for(auto& token: tokens){  
            if(token == "+" || token == "-" || token == "*" || token == "/"){
                stack.push(calculate(stack, token));
                continue;
            }
            
            stack.push(stoi(token));
            
        }

        return stack.top();
    }
};