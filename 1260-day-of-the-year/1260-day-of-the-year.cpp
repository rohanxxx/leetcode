class Solution {
public:
    int dayOfYear(string date) {
        int year = stoi(date.substr(0, 4));
        int month = stoi(date.substr(5, 2));
        int day = stoi(date.substr(8, 2));
        vector<int> months = {
            0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
        };

        int dayCount = 0;
        for(int i = 0; i < month; i++){
            dayCount += months[i];
        }
        dayCount += day;
        if(month > 2){
            if(year%400 == 0){
                dayCount++;
            }
            else{
                if(year%4 == 0 && year%100 != 0){
                    dayCount++;
                }
            }
        }
        return dayCount;
    }
};