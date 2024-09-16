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
    int maxDiameter;
    int dfs(Node* root){

        if(root->children.empty()) return 1;
        
        // min heap que in c++
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(auto& child: root->children){
            int dept = dfs(child);
            pq.push(dept);
            if(pq.size()>2){
                pq.pop();
            }
        }
        
        if(pq.size() == 2){
            int firstHigh = pq.top(); pq.pop();
            int secondHigh = pq.top(); pq.pop();
            maxDiameter = max(maxDiameter, firstHigh+secondHigh);
            return secondHigh+1;
        }

        // if(pq.size() == 1){
            int high = pq.top(); pq.pop();
            maxDiameter = max(maxDiameter, high);
            return high+1;
        // }

        // return 0;
    }

    int diameter(Node* root) {
        maxDiameter = 0;
        dfs(root);
        return maxDiameter;
    }
};