class Solution {
public:
    int lateFee(vector<int>& daysLate) {
        int lateFee = 0;
        for(auto dayLate: daysLate){
            if(dayLate == 1){
                lateFee += 1;
            }
            else if(dayLate >= 2 && dayLate <= 5){
                lateFee += (dayLate*2);
            }
            else{
                lateFee += (dayLate*3);
            }
        }

        return lateFee;
    }
};