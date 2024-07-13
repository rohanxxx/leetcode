#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> graph;

        // Step 1: Build the graph from the equations
        for (int i = 0; i < equations.size(); i++) {
            string dividend = equations[i][0];
            string divisor = equations[i][1];
            double quotient = values[i];

            // if (graph.find(dividend) == graph.end()){
                // graph[dividend] = unordered_map<string, double>();
                // graph[dividend][divisor] = quotient;
            // }
            // if (graph.find(divisor) == graph.end()){
                // graph[divisor] = unordered_map<string, double>();
                // graph[divisor][dividend] = 1 / quotient;
            // }
            graph[dividend][divisor] = quotient;
            graph[divisor][dividend] = 1 / quotient;
        }

        // Step 2: Evaluate each query via backtracking (DFS)
        // by verifying if there exists a path from dividend to divisor
        vector<double> results;
        for (int i = 0; i < queries.size(); i++) {
            string dividend = queries[i][0];
            string divisor = queries[i][1];

            if (graph.find(dividend) == graph.end() || graph.find(divisor) == graph.end())
                results.push_back(-1.0);
            else if (dividend == divisor)
                results.push_back(1.0);
            else {
                unordered_set<string> visited;
                results.push_back(backtrackEvaluate(graph, dividend, divisor, 1.0, visited));
            }
        }

        return results;
    }

private:
    double backtrackEvaluate(unordered_map<string, unordered_map<string, double>>& graph, string currNode, string targetNode, double accProduct, unordered_set<string>& visited) {
        // Mark the visit
        visited.insert(currNode);
        double ret = -1.0;

        auto neighbors = graph[currNode];
        if (neighbors.find(targetNode) != neighbors.end()) {
            ret = accProduct * neighbors[targetNode];
        } else {
            for (auto& pair : neighbors) {
                string nextNode = pair.first;
                if (visited.find(nextNode) != visited.end())
                    continue;
                ret = backtrackEvaluate(graph, nextNode, targetNode, accProduct * pair.second, visited);
                if (ret != -1.0)
                    break;
            }
        }

        // Unmark the visit for the next backtracking
        visited.erase(currNode);
        return ret;
    }
};
