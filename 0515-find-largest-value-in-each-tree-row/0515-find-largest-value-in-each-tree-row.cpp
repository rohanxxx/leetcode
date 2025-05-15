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
    tree has left and right child
    Input: root = [1,3,2,5,3,null,9]
    Output: [1,3,9]
                                1
                            3       2
                        5   3           9
    ans = {1, 3, 9}
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        //first edge check if root is null return empty vector
        if(root == NULL){
            return vector<int>();
        }
        //here I store each row's maxVal
        vector<int> ans;
        //push the root to the queue
        queue<TreeNode*> q; q.push(root);
        //use a while loop to traverse the root
        //TC: O(N)
        while(!q.empty()){
            int levelSize = q.size();
            int maxVal = INT_MIN;
            //level order traversal happens in other words the whole row traversal 
            for(int i = 0; i < levelSize; i++){
                TreeNode* curNode = q.front(); q.pop();
                int curNodeVal = curNode->val;
                maxVal = max(maxVal, curNodeVal);       //keep checking each levels max
                //we push the next level's treeNodes
                if(curNode->left){
                    q.push(curNode->left);
                }
                if(curNode->right){
                    q.push(curNode->right);
                }
            }
            ans.push_back(maxVal);
        }
        return ans;
    }
};