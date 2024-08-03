class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        if (!root) return {};

        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);

        while (!nodesQueue.empty()) {
            TreeNode* currentNode = nodesQueue.front();
            nodesQueue.pop();

            if (currentNode->left) {
                nodesQueue.push(currentNode->left);
                if (toDeleteSet.find(currentNode->left->val) != toDeleteSet.end()) currentNode->left = NULL;
            }

            if (currentNode->right) {
                nodesQueue.push(currentNode->right);
                if (toDeleteSet.find(currentNode->right->val) != toDeleteSet.end()) currentNode->right = NULL;
            }

            if (toDeleteSet.find(currentNode->val) != toDeleteSet.end()) {
                if (currentNode->left) forest.push_back(currentNode->left);
                if (currentNode->right) forest.push_back(currentNode->right);
            }
        }

        if (toDeleteSet.find(root->val) == toDeleteSet.end()) forest.push_back(root);

        return forest;
    }
};