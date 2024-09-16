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

        for(int i = 0; i < n; i++){
            if(graph[i] == n-1) return i;
        }

        return -1;
    }
};