class Solution {
public:
/*
    each turn we choose two heaviest stone
    and smash them together
    suppose the weights of heaviest two stones are x & y with x <= y
    if(x == y) both are destroyed
    if(x != y) then x is destroyed and y stones weight changes to y = y-x;
    the last remaining stone.

                y x
    8x 7x 4x 2x 2x 1x 1 1 1 
    

*/
    //TC: O(N+N)= O(2N) = O(N)
    int lastStoneWeight(vector<int>& stones) {
        //SC: O(N)
        priority_queue<int> pq;
        //TC: O(N)
        for(int stone: stones){
            pq.push(stone);
        }
        //TC: O(N)
        while((int)pq.size() > 1){
            int y = pq.top(); pq.pop();
            int x = pq.top(); pq.pop();
            if(y != x){
                pq.push(y-x);
            }
        }
        if(!pq.empty()){
            return (int)pq.top();
        }
        return 0;
    }
};