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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> mp;
        unordered_map<int, bool> hasParent;

        for(auto d: descriptions){
            int parentVal = d[0];
            int childVal = d[1];
            int isLeft = d[2];

            TreeNode* parentNode = NULL;
            TreeNode* childNode = NULL;

            if(mp.find(parentVal) == mp.end()) parentNode = new TreeNode(parentVal);
            else parentNode = mp[parentVal];

            if(mp.find(childVal) == mp.end()) childNode = new TreeNode(childVal);
            else childNode = mp[childVal];

            if(isLeft) parentNode->left = childNode;
            else parentNode->right = childNode;

            hasParent[childVal] = true;
            mp[childVal] = childNode;
            mp[parentVal] = parentNode;
        }

        TreeNode* rootNode = NULL;
        for(auto& [nodeVal, node]: mp){
            if(!hasParent[nodeVal]) rootNode = node;
        }

        return rootNode;
    }
};