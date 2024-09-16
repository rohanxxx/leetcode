/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        vector<int> graph(n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i != j){
                    if(knows(i, j) && !knows(j, i)){
                        graph[j]++;
                    }
                }
            }
        }

        int count = 0;
        int index = -1;
        for(int i = 0; i < n; i++){
            cout << "graph[" << i << "]: " << graph[i] << endl;
            // if(graph[i] == 0) {count++; index = i;}
            if(graph[i] == n-1) return i;
        }

        // if(count == 1)  return index;

        return -1;
    }
};