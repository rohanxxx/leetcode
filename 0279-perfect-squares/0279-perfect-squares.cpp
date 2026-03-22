class Solution {
public:
    int numSquares(int n) {
        vector<long long> sq;
        for(int i = 1; i*i <= n; i++){
            sq.push_back(i*i);
        }
        queue<int> q;
        unordered_set<int> visited;

        q.push(n);
        visited.insert(n);

        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int rem = q.front();
                q.pop();

                if(rem == 0) return level;
                if(rem < 0) continue;
                for(int square: sq){
                    int nextRem = rem-square;
                    if(visited.find(nextRem) == visited.end()){
                        q.push(nextRem);
                        visited.insert(nextRem);
                    }
                }
            }
            level++;
        }

        return -1;
    }
};