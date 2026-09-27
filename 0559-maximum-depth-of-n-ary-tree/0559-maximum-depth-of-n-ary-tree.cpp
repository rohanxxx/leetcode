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
    int maxDepth(Node* root) {
        if(root == NULL){
            return 0;
        }
        queue<pair<Node*, Node*>> q;
        q.push({root, NULL});

        int depth = 0;
        while(!q.empty()){
            depth++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                Node* node = q.front().first;
                Node* parent = q.front().second;
                
                q.pop();

                for(auto adjn: node->children){
                    if(adjn == node){
                        continue;
                    }
                    q.push({adjn, node});
                }
            }
        }

        return depth;
    }
};