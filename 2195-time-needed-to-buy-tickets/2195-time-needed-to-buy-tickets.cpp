class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int willBuyTicket = tickets[k];
        int timeNeeds = willBuyTicket;
        for(int i = 0; i < tickets.size(); i++){
            if(i < k){
                if(tickets[i] <= willBuyTicket) timeNeeds+= tickets[i];
                else timeNeeds += willBuyTicket;
            }
            else{
                if(i > k){
                    if(tickets[i] <= willBuyTicket-1) timeNeeds += tickets[i];
                    else timeNeeds += (willBuyTicket-1);
                }
            }
        }
        return timeNeeds;
    }
};