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
class Solution {
public:
    int closestValue(TreeNode* root, double target) {
        if(root == NULL) return -1;
        queue<TreeNode*> q;
        q.push(root);

        int closestValue;
        double difference = double(INT_MAX);

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                TreeNode* node = q.front(); q.pop();
                int nodeVal = node->val;
                double currDif = abs(double(nodeVal)-target);
                
                if(currDif <= difference){
                    if(currDif == difference){
                        closestValue = min(closestValue, nodeVal);
                    }
                    else{
                        closestValue = node->val;
                    }
                    difference = currDif;
                }

                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
            }
        }
        return closestValue;
    }
};