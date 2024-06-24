class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int squareCount = 0, circleCount = 0;
        for(auto student: students){
            if(student) squareCount++;
            else circleCount++;
        }

        for(auto sandwich: sandwiches){
            if(sandwich == 0 && circleCount == 0) return squareCount;
            if(sandwich == 1 && squareCount == 0) return circleCount;
            if(sandwich == 0) circleCount--;
            else squareCount--;
        }
        return 0;
    }
};