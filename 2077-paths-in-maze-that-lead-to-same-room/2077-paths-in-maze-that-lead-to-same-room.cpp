/*
    undirected graph

    confused with with the confusion score cycle
    -> the designer of the maze wants to know how confusing the maze is
    -> the confusion score of the maze is the number of different cycle of length 3
    -> two cycles are considered to be different if one or more of the rooms visited in the first cycle
    is not in the second cycle

    return the confusion score of the maze

    3 - 1 - 2 - 5
      \ | /
        4

    1x 3x 4 2 

    count -> 1
*/
class Solution {
public:
    int numberOfPaths(int n, vector<vector<int>>& corridors) {
        vector<unordered_set<int>> graph(n + 1);

        for(auto& it : corridors){
            graph[it[0]].insert(it[1]);
            graph[it[1]].insert(it[0]);
        }

        int count = 0;

        for(int node = 1; node <= n; node++){

            if(graph[node].size() < 2){
                continue;
            }

            for(auto adjNode : graph[node]){

                // enforce ordering
                if(adjNode <= node){
                    continue;
                }

                for(auto adj : graph[adjNode]){

                    if(adj <= adjNode){
                        continue;
                    }

                    // triangle exists
                    if(graph[node].find(adj) != graph[node].end()){
                        count++;
                    }
                }
            }
        }

        return count;
    }
};