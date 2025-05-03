class Solution {
public:
    int calculate(string s) {
        stack<int> stack;
        int operand = 0;
        int result = 0;
        int sign = 1;  // 1 means positive, -1 means negative

        for (int i = 0; i < s.length(); i++) {
            char ch = s[i];

            if (isdigit(ch)) {
                operand = 10 * operand + (ch - '0');
            } else if (ch == '+') {
                result += sign * operand;
                sign = 1;
                operand = 0;
            } else if (ch == '-') {
                result += sign * operand;
                sign = -1;
                operand = 0;
            } else if (ch == '(') {
                stack.push(result);
                stack.push(sign);
                sign = 1;
                result = 0;
            } else if (ch == ')') {
                result += sign * operand;
                result *= stack.top(); stack.pop(); // sign before parenthesis
                result += stack.top(); stack.pop(); // result before parenthesis
                operand = 0;
            }
        }

        return result + (sign * operand);
    }
};