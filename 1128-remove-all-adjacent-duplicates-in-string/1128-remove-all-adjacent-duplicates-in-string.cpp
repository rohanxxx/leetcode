class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stack;
        for(int i = 0; i < s.length(); i++){
            if(stack.empty()) stack.push(s[i]);
            else{
                if(s[i] == stack.top()) stack.pop();
                else stack.push(s[i]);
            }
        }
        string ans = "";
        while(!stack.empty()){
            ans += stack.top(); stack.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};