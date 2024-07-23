class Solution {
public:
    bool leapYear(int year){
        if(year%4 == 0 && year%100 != 0) return true;
        if(year%400 == 0) return true;
        return false;
    }
    int daysInMonth(int m, int y){
        if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
        if(m == 2){
            if(leapYear(y)) return 29;
            return 28;
        }
        return 30;
    }
    int dateToInt(string s){
        int year = stoi(s.substr(0,4));
        int month = stoi(s.substr(5,2));
        int day = stoi(s.substr(8,2));

        int dayCount = 0;
        for(int y = 1971; y < year; y++){
            if(leapYear(y)) dayCount += 366;
            else dayCount += 365;
        }
        for(int m = 0; m < month; m++){
            dayCount += daysInMonth(m, year);
        }

        dayCount += day;
        return dayCount;
    }
    int daysBetweenDates(string date1, string date2) {
        return abs(dateToInt(date1) - dateToInt(date2)); 
    }
};