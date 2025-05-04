class Solution {
public:
/*
    ()
    {}
    []
    s = ())
    s = ((()))
    stack = 
*/
    int minAddToMakeValid(string s) {
        int count = 0;
        stack<char> stack;
        for(char c: s){
            if(c == '('){
                stack.push(c);
            }
            else if(c == ')'){
                if(stack.empty()){
                    count++;
                }
                else{
                    stack.pop();
                }
            }
        }
        if(stack.size() > 0) return (int)stack.size()+count;
        return count;
    }
};