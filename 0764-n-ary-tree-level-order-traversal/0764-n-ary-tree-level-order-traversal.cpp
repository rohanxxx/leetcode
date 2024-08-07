/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        queue<Node*> q; q.push(root);
        vector<vector<int>> result;
        
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            // cout << "size: " << size << endl;
            for(int i = 0; i < size; i++){
                Node* cur = q.front(); q.pop();

                // cout << cur->val << " ";
                level.push_back(cur->val);
                for(int j = 0; j < cur->children.size(); j++){
                    q.push(cur->children[j]);
                }
            }
            result.push_back(level);
            // cout << endl << endl;
        }

        return result;
    }
};