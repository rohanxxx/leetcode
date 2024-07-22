class Solution {
public:
    int WHITE = 1;
    int GRAY = 2;
    int BLACK = 3;

    void dfs(int node, map<int, int>& color, map<int, vector<int>>& adjList, bool& isPossible, vector<int>& topologicalOrder){
        if(!isPossible) return;
        color[node] = GRAY;
        for(int neighbor: adjList[node]){
            if(color[neighbor] == WHITE){
                dfs(neighbor, color, adjList, isPossible, topologicalOrder);
            }
            else{
                if(color[neighbor] == GRAY){
                    isPossible = false;
                }
            }
        }

        color[node] = BLACK;
        topologicalOrder.push_back(node);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        bool isPossible = true;
        map<int, int> color;
        map<int, vector<int>> adjList;
        vector<int>topologicalOrder;

        for(int i = 0; i < numCourses; i++) color[i] = WHITE;

        //create the graph here
        for(auto& prereq: prerequisites){
            int dest = prereq[0];
            int src = prereq[1];
            adjList[src].push_back(dest);
        }

        //start recursing
        for(int i = 0; i < numCourses && isPossible; i++){
            if(color[i] == WHITE){
                dfs(i, color, adjList, isPossible, topologicalOrder);
            }
        }

        vector<int> order;
        if(isPossible){
            order.resize(numCourses);
            for(int i = 0; i < numCourses; i++){
                order[i] = topologicalOrder[numCourses-i-1];
            }
        }

        return order;
    }
};