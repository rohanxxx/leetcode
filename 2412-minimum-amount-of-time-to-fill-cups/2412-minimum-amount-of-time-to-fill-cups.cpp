class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        for(int i: amount){
            if(i > 0) pq.push(i);
        }

        int time = 0;
        while(!pq.empty()){
            time++;
            int c1 = 0, c2 = 0;
            c1 = pq.top()-1; pq.pop();
            if(!pq.empty()){
                c2 = pq.top()-1; pq.pop();
            }
            if(c1 > 0) pq.push(c1);
            if(c2 > 0) pq.push(c2);
        }
        return time;
    }
};