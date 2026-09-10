/*
    0 -> 1
    1 -> -2
    2 -> 4
    3 -> 0
    4 -> -2
    5 -> -1
    6 -> -1

    parent:
    0 -> -1
    1 -> 0

    create a 
    vector<vector<int>> v; holds the children and parent;

*/
class Solution {
public:
    int dfs1(int node, vector<int>& value, vector<vector<int>>& graph){
        int sum = value[node];
        //iterate through the childs
        for(auto adjn: graph[node]){
            sum += dfs1(adjn, value, graph);
        }
        return value[node] = sum;
    }

    int dfs2(int node, vector<int>& value, vector<vector<int>>& graph){
        if(value[node] == 0){
            return 0;
        }

        int count = 0;
        for(auto adjn: graph[node]){
            count += dfs2(adjn, value, graph);
        }
        return count+1;
    }

    int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
        //step->1 create the graph
        vector<vector<int>> graph(nodes);
        int root = -1;
        for(int i = 0; i < nodes; i++){
            if(parent[i] == -1){
                root = i;
                continue;
            }
            graph[parent[i]].push_back(i);
        }

        //setting up the sum of each nodes total subtrees
        dfs1(root, value, graph);
        //counts the nodes the has subtree sum != 0
        return dfs2(root, value, graph);
    }
};