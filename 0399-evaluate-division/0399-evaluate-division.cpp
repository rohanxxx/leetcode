class Solution {
public:
    double dfs(
        unordered_map<string, unordered_map<string, int>>& graph, 
        string& currNode, 
        string& targetNode, 
        double product, 
        unordered_set<string>& visited
    ){
        visited.insert(currNode);
        double ret = -1.0;

        auto neighbors = graph[currNode];
        if(neighbors.find(targetNode) != neighbors.end()){
            ret = double(product)*double(neighbors[targetNode]);
        }
        else{
            for (auto& pair: neighbors){
                string nextNode = pair.first;
                //skips dup
                if(visited.find(nextNode) != visited.end()) continue;
                ret = dfs(graph, nextNode, targetNode, double(product)*double(pair.second), visited);
                if(ret != -1) break;
            }
        }
        return ret;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, int>> graph;

        string dividend, divisor;
        double quotient = 0.0;
        //build the graph
        for(int i = 0; i < equations.size(); i++){
            dividend = equations[i][0]; divisor = equations[i][1];
            quotient = values[i];
            graph[dividend][divisor] = double(quotient);
            graph[divisor][dividend] = double(1)/quotient;
        }

        vector<double> result;

        for(auto &query: queries){
            dividend = query[0]; divisor = query[1];
            if(graph.find(dividend) == graph.end()||graph.find(divisor)==graph.end()) result.push_back(-1.0);
            else if(dividend == divisor) result.push_back(1.0);
            else{
                unordered_set<string> visited;
                result.push_back(dfs(graph, dividend, divisor, double(1.0), visited));
            }
        }
        return result;
    }
};