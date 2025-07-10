/*
    Input: pattern = "IIIDIDDD"
    Output: "123549876"

    I I I D I D D D
    1 2 3 5 4 9 8 7 6
*/
class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        
        string ans = "";
        stack<int> stack;
        for(int i = 0; i <= n; i++){
            int digit = i+1;
            stack.push(digit);
            if(i == n || pattern[i] == 'I'){
                while(!stack.empty()){
                    ans += to_string(stack.top());
                    stack.pop();
                }
            }
        }

        return ans;
    }
};