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
    Input: descriptions = [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]
    Output: [50,20,80,15,17,19]

    [[20,15,1],[20,17,0],[50,20,1],[50,80,0],[80,19,1]]

    50 - 80
     \        \
      20 - 17 19
        \
        15

    
    15 - 20 - 50
       /    /
    17.  80
        /
    19
 */
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> map;
        unordered_map<TreeNode*, TreeNode*> parentMap; 
        for(auto it: descriptions){
            int parent = it[0];
            int child = it[1];
            int flag = it[2];
            
            TreeNode* parentNode = NULL;
            TreeNode* childNode = NULL;
            
            if(map[parent] == NULL){
                parentNode = new TreeNode(parent);
                map[parent] = parentNode;
            }
            else{
                parentNode = map[parent];
            }
            
            if(map[child] == NULL){
                childNode = new TreeNode(child);
                map[child] = childNode;
            }
            else{
                childNode = map[child];
            }
            
            //assigning left or right
            if(flag == 1){
                parentNode->left = childNode;
            }
            else{
                parentNode->right = childNode;
            }

            parentMap[childNode] = parentNode;
        }

        for(auto it: map){
            if(parentMap[map[it.first]] == NULL){
                return map[it.first];
            }
        }

        return NULL;
    }
};