/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

 /*
    Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
    Output: 20
                                        1
                                    4       3
                                2   4     2   5
                                            4   6

            4: left => {curSum = 0, leftMax = INT_MAX , rightMax = INT_MIN} right = { curSum = 0, leftMax = INT_MAX, rightMax = INT_MIN}
            6: left => {curSum = 0, leftMax = INT_MAX , rightMax = INT_MIN} right = { curSum = 0, leftMax = INT_MAX, rightMax = INT_MIN}
                                            left.rightMax < 4 < right.leftMax
            return 4: {curSum = 4, leftMax = 4 , rightMax = 4}
                                <    5    <
            return 6: {curSum = 6, leftMax = 6 , rightMax = 6}

            return 2: {curSum = 2, leftMax = 2 , rightMax = 2}
                             < 3 <
            return 5: {curSum = 15, leftMax = 5 , rightMax = 6}
 */
class Solution {
public:
    int maxSum;

    class BSTchecker {
    public:
        int curSum;
        int minVal;
        int maxVal;
        BSTchecker() {
            curSum = 0;
            minVal = INT_MAX;
            maxVal = INT_MIN;
        }
        BSTchecker(int sum, int minV, int maxV) {
            curSum = sum;
            minVal = minV;
            maxVal = maxV;
        }
    };

    BSTchecker dfs(TreeNode* root) {
        if (root == NULL) {
            return BSTchecker(0, INT_MAX, INT_MIN);
        }

        BSTchecker leftNode = dfs(root->left);
        BSTchecker rightNode = dfs(root->right);

        // If current subtree is BST
        if (leftNode.maxVal < root->val && root->val < rightNode.minVal) {
            int curSum = root->val + leftNode.curSum + rightNode.curSum;
            maxSum = max(maxSum, curSum);

            int minSubtree = min(root->val, leftNode.minVal);  // may be INT_MAX
            int maxSubtree = max(root->val, rightNode.maxVal); // may be INT_MIN
            return BSTchecker(curSum, minSubtree, maxSubtree);
        }

        // Not a BST
        return BSTchecker(INT_MIN, INT_MIN, INT_MAX);
    }

    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        dfs(root);
        return maxSum;
    }
};