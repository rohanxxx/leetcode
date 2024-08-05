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
    int goodPairCount = 0;
    vector<int> dfs(TreeNode* currentNode, int& distance){
        if(!currentNode)return {};
        if(currentNode->left == NULL && currentNode->right == NULL) return {1};
        vector<int> left = dfs(currentNode->left, distance);
        vector<int> right = dfs(currentNode->right, distance);

        vector<int> parent;
        for(auto& l: left){
            parent.push_back(l+1);
            for(auto& r: right){
                if(l+r <= distance) goodPairCount++;
            }
        }
        /*
        vector<int> parent;
        for(auto& l: left){
            parent.push_back(l+1);
        }*/
        for(auto& r: right){
            parent.push_back(r+1);
        }

        return parent;
    }

    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return goodPairCount;
    }
};