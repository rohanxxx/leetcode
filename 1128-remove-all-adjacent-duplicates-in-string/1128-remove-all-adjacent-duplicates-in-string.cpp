class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        // stack.push(s[0]);

        for(int i = 0; i < s.length(); i++){
            if(stack.empty()){
                stack.push(s[i]);
                continue;
            }
            if(stack.top() != s[i]) stack.push(s[i]);
            else stack.pop();
        }

        string ans = "";
        while(!stack.empty()){
            ans += stack.top();
            stack.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};