class Solution {
public:
    int bestClosingTime(string customers) {
        int minPenalty = 0, curPenalty = 0;
        int earliestHour = 0;

        for(int i = 0; i < customers.length(); i++){
            if(customers[i] == 'Y') curPenalty--;
            else curPenalty++;

            if(curPenalty < minPenalty){
                earliestHour = i+1;
                minPenalty = curPenalty;
            }
        }

        return earliestHour;
    }
};