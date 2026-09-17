class Solution {
public:
    int dfs(int node, int parent, int& goodNodes, vector<vector<int>>& tree){
        int sum = 0;
        vector<int> childCount;
        for(auto adjn: tree[node]){
            if(adjn == parent){
                continue;
            }
            int count = dfs(adjn, node, goodNodes, tree);
            
            sum += count;
            childCount.push_back(count);
        }

        //bool check = true;
        for(int i = 1; i < childCount.size(); i++){
            if(childCount[i-1] != childCount[i]){
                //check = false;
                return sum+1;
            }
        }
        goodNodes++;
        return sum+1;
    }
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size();
        //1) contruct the tree
        vector<vector<int>> tree(n+1);
        for(auto it: edges){
            tree[it[0]].push_back(it[1]);
            tree[it[1]].push_back(it[0]);
        }
        //2) start traversing from the root
        int goodNodes = 0;
        dfs(0, -1, goodNodes, tree);
        //3) we do dfs alongside keep track of it's child nodes that are equal
        return goodNodes;
    }
};