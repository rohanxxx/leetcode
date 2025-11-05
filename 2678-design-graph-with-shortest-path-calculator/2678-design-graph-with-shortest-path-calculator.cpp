//edges = front, to edgeCost
//addEdge there would be no edge between the two nodes before adding this one
//shortest path returns the minimum cost for node1 to node2 if no path exists

/*
    [[0, 2, 5], [0, 1, 2], [1, 2, 1], [3, 0, 3]]]

                 3
                 |  3
            2    >. 5
        1 <----- 0 ----> 2
         \_____________>|
            1
*/
class Graph {
private:
    int size = 0;
    vector<vector<pair<int, int>>> graph;
public:
    //O(N+E)
    Graph(int n, vector<vector<int>>& edges) {
        //initialize my graph here
        size = n;
        graph.resize(n);
        for(auto edge: edges){
            graph[edge[0]].push_back({edge[1], edge[2]});
        }
    }
    
    //TC: O(1)
    void addEdge(vector<int> edge) {
        //update the graph here
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];

        if(u > size) return;

        if(u == size){
            size++;
            graph.push_back({{v, cost}});
        }

        graph[u].push_back({v, cost});
    }

    //TC: O(NlogN)
    int shortestPath(int node1, int node2) {

        //O(N)
        vector<int> dist (size, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        pq.push({0, node1});
        dist[node1] = 0;
        
        //O(E+NlogN)
        while(!pq.empty()){
            auto it = pq.top();
            int curCost = it.first;
            int curNode = it.second;

            pq.pop();

            //returns the shortest cost
            if(curNode == node2){
                return curCost;
            }

            //now you have traverse & update
            for(auto edge: graph[curNode]){
                int edgeNode = edge.first;
                int edgeCost = edge.second;
                int newCost = edgeCost + curCost;
                //update the dist
                //push it to the pq
                if(newCost < dist[edgeNode]){
                    pq.push({newCost, edgeNode});
                    dist[edgeNode] = newCost;
                }
            }
        }
        
        return -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */