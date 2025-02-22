class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n = tickets.size();
        queue<int> q;
        for(int i = 0; i < n; i++){
            q.push(i);
        }
        int t = 0;
        while(!q.empty()){
            t++;
            int index = q.front();
            tickets[index]--; q.pop();
            if(index == k && tickets[index] == 0){
                return t;
            }
            if(tickets[index] != 0){
                q.push(index);
            } 
        }
        return -1;
    }
};