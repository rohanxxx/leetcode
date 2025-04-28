/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "";
        queue<TreeNode*> q; q.push(root);
        string encode = (to_string(root->val) + ",");
        while(!q.empty()){
            TreeNode* curNode = q.front(); q.pop();
            if(curNode->left){
                encode += (to_string(curNode->left->val) + ",");
                q.push(curNode->left);
            }
            else{
                encode += ("#,");
            }
            if(curNode->right){
                encode += (to_string(curNode->right->val) + ",");
                q.push(curNode->right);
            }
            else{
                encode += ("#,");
            }
        }
        cout << encode << endl;
        return encode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return NULL;
        stringstream ss(data);
        
        string str;
        getline(ss, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q; q.push(root);
        
        while(!q.empty()){
            TreeNode* curNode = q.front(); q.pop();
            //this will assign the left node of the curNode
            getline(ss, str, ',');
            if(str == "#"){
                curNode->left = NULL;
            }
            else{
                curNode->left = new TreeNode(stoi(str));
                q.push(curNode->left);
            }

            getline(ss, str, ',');
            if(str == "#"){
                curNode->right = NULL;
            }
            else{
                curNode->right = new TreeNode(stoi(str));
                q.push(curNode->right);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));