/*
    leetcode
    edocteel
    reverse() ->leetcode
*/
class Solution {
public:
    string makeGood(string s) {
        //declare a stack where we will insert only the valid elements by checking the top
        //SC: O(N)
        stack<char> stack;
        //for loop to iterate all the characters of s
        //TC: O(N)
        for(auto c: s){
            //if stack is not empty then compare the top element of stack with curr to check if it's a
            //bad string or not
            if(!stack.empty() && abs(stack.top()-c) == 32){
                stack.pop();
                continue;
            }
            stack.push(c);
        }

        string ans = "";
        //TC: O(N)
        while(!stack.empty()){
            ans.push_back(stack.top());
            stack.pop();
        }

        //TC: O(N)
        reverse(ans.begin(), ans.end());

        return ans;
    }
};