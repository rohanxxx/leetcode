class Solution {
public:
    string removeStars(string s) {
        stack<char> stack;
        for(char c: s){
            if(stack.empty()) {
                stack.push(c);
                continue;
            }
            if(c == '*'){
                if(!stack.empty()) stack.pop();
                continue;
            }
            stack.push(c);
        }

        string ans = "";
        while(!stack.empty()){
            ans += stack.top(); stack.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};