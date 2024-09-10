class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> res(s.length() + 1);
        stack<int> stack;
        int j = 0;
        
        for (int i = 1; i <= s.length(); ++i) {
            if (s[i - 1] == 'I') {
                stack.push(i);
                while (!stack.empty()) {
                    res[j++] = stack.top();
                    stack.pop();
                }
            } else {
                stack.push(i);
            }
        }
        
        stack.push(s.length() + 1);
        while (!stack.empty()) {
            res[j++] = stack.top();
            stack.pop();
        }
        
        return res;
    }
};