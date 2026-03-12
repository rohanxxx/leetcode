/*
    num = "1432219", k = 3


*/
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> stack;
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

        while(!stack.empty() && k > 0){
            stack.pop(); k--;
        }

        string newNum = "";
        while(!stack.empty()){
            newNum.push_back(stack.top());
            stack.pop();
        }

        while(!newNum.empty() && newNum.back() == '0') newNum.pop_back();

        reverse(newNum.begin(), newNum.end());

        if(newNum.empty()) return "0";
        return newNum;
    }
};