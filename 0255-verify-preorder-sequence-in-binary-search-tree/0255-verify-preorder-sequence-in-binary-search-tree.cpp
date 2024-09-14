class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int root = INT_MIN;
        stack <int> stack;
        for(int i = 0; i < preorder.size(); i++){
            while(!stack.empty() && preorder[i] > stack.top()){
                root = stack.top();
                stack.pop();
            }

            if(preorder[i] < root) return false;
            stack.push(preorder[i]);
        }
        return true;
    }
};