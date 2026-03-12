/*
    num = "1432219", k = 3


*/
class Solution {
public:
    //TC: O(N+N+N+N+N) = O(5N)
    string removeKdigits(string num, int k) {
        stack<char> stack;

        //TC: O(N)
        for(char c: num){
            if(stack.empty()){
                stack.push(c);
                continue;
            }
            while(!stack.empty() && stack.top() > c && k > 0){
                stack.pop();
                k--;
            }
            stack.push(c);
        }

        //TC:O(N)
        while(!stack.empty() && k > 0){
            stack.pop(); k--;
        }

        string newNum = "";

        //TC: O(N)
        while(!stack.empty()){
            newNum.push_back(stack.top());
            stack.pop();
        }

        //TC: O(N)
        while(!newNum.empty() && newNum.back() == '0') newNum.pop_back();

        //TC: O(N)
        reverse(newNum.begin(), newNum.end());

        if(newNum.empty()) return "0";
        return newNum;
    }
};