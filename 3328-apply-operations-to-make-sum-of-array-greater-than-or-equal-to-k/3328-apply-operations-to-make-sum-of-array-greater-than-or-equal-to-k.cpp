class Solution {
public:
    int minOperations(int k) {
        int minOps = INT_MAX;
        for(int i = 1; i <= k/2; i++){
            int quo, ops;
            if(k % i == 0){
                quo = k/i;
                ops = i-1;
                minOps = min(minOps, (quo-1)+ops);
                continue;
            }
            quo = k/i;
            ops = i-1;
            if(quo*i+ops >= k){
                minOps = min(minOps, quo+ops);
            }
        }
        if(minOps == INT_MAX){
            return 0;
        }

        return minOps;
    }
};