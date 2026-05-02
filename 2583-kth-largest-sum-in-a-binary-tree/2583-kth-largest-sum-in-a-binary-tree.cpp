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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;

        if(root){
            q.push(root);
        }

        //O(NlogN)
        while(!q.empty()){
            int levelSize = q.size();

            long long levelSum = 0;
            for(int i = 0; i < levelSize; i++){
                TreeNode* node = q.front(); q.pop();
                levelSum += (long long)node->val;

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            //cout << "levelSum " << levelSum << endl;
            //O(logN)
            if(levelSum != 0){
                minHeap.push(levelSum);
            }

            if(minHeap.size() > k){
                minHeap.pop();
            }
        }

        if(minHeap.size() == k){
            return (long long)minHeap.top();
        }

        return -1;
    }
};