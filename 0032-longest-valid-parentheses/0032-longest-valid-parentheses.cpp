class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if(len == 0) return 0;

        stack<int> stack; stack.push(-1);
        int maxLen = 0;

        for(int i = 0; i < len; i++){
            if(s[i] == '('){
                stack.push(i);
            }
            else{
                stack.pop();
                if(stack.empty()) stack.push(i);
                else maxLen = max(maxLen, i-stack.top());
            }
        }

        return maxLen;
    }
};