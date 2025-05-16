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

                          50
                         /  \
                       20   80
                       /\   /
                     15  17 19

    unordered_map<int, TreeNode*> tree;
    map[20] = new TreeNode(20) -> left = new TreeNode(15)               15 17 20
    map[15] = treeNode(15)                                      
    map[17] = treeNode(17)                                              
    map[50] = if the value 20 doesn't exist then create new TreeNode(20) otherwise point it to map[20] 20 has 

    if(!hasparent[map[id]]) return the map[id];

    return NULL?
 */

 /*
 */

void connectTree(int& parent, int& child, int& isLeft, unordered_map<int, TreeNode*>& treeMap){
    if(treeMap.find(child) == treeMap.end()){
        treeMap[child] = new TreeNode(child);
    }
    if(isLeft == 1){
        treeMap[parent]->left = treeMap[child];
    }
    else{
        treeMap[parent]->right = treeMap[child];
    }
} 
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        //first we will construct the tree
        //SC: O(N+N) = O(2N) = O(N)
        unordered_map<int, TreeNode*> treeMap;
        unordered_map<int, int> hasParent;

        //TC: O(N)
        for(auto it: descriptions){
            int parent = it[0];
            int child = it[1];
            int isLeft = it[2];
            hasParent[child] = 1;
            //if it already doesn't exist create a new treeNode
            if(treeMap.find(parent) == treeMap.end()){
                treeMap[parent] = new TreeNode(parent);
                connectTree(parent, child, isLeft, treeMap);
            }
            else{
                connectTree(parent, child, isLeft, treeMap);
            }
        }
        TreeNode* root = NULL;
        //here we will identify the parent
        //TC: O(N)
        for(auto it: descriptions){
            int parent = it[0];
            if(hasParent[parent] == 0){
                root = treeMap[parent];
                return root;
            }
        }
        return root;
    }
};