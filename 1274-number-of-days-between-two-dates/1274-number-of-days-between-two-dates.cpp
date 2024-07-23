class Solution {
public:
    bool leapYear(int y){
        if(y % 4 == 0 && y%100 != 0) return true;
        if (y%400 == 0) return true;
        return false; 
    }
    int daysInMonth(int m, int y){
        if(m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) return 31;
        if(m == 2){
            if(leapYear(y)) return 29;
            else return 28;
        }
        
        return 30;
    
    }
    int date_to_int(string date){
        int y = stoi(date.substr(0,4));
        int m = stoi(date.substr(5,2));
        int d = stoi(date.substr(8,2));
        
        int dayCount = 0;

        for(int i = 1971; i < y; i++){
            if(leapYear(i)) dayCount += 366;
            else dayCount += 365;
        }

        for(int i = 1; i < m; i++){
            dayCount += daysInMonth(i, y);
        }

        return dayCount+d;
    }
    int daysBetweenDates(string date1, string date2) {
        return abs(date_to_int(date2) - date_to_int(date1));
    }
};