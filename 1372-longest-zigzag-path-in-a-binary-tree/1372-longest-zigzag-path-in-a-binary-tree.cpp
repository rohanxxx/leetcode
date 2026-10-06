class Solution {
public:
    int ans = 0;
    void dfs(int dir, TreeNode* node, int len){
        ans = max(ans, len);
        if(node->left){
            //coming from right (or root) then going left keeps the zigzag
            if(dir == 2 || dir == 0){
                dfs(1, node->left, len + 1);
            }
            //coming from left and going left again restarts the zigzag
            else{
                dfs(1, node->left, 1);
            }
        }
        if(node->right){
            //coming from left (or root) then going right keeps the zigzag
            if(dir == 1 || dir == 0){
                dfs(2, node->right, len + 1);
            }
            //coming from right and going right again restarts the zigzag
            else{
                dfs(2, node->right, 1);
            }
        }
    }
    int longestZigZag(TreeNode* root) {
        dfs(0, root, 0);
        return ans;
    }
};