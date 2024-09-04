class Solution {
public:
    bool confusingNumber(int n) {
        int copy = n;
        int newNum = 0;
        while(n != 0){
            int pop = n%10; n /= 10;
            if(pop == 0 || pop == 1 || pop == 6 || pop == 8 || pop == 9){
                newNum *= 10;
                if(pop == 0) newNum += pop;
                if(pop == 1) newNum += pop;
                if(pop == 6) newNum += 9;
                if(pop == 8) newNum += pop;
                if(pop == 9) newNum += 6;
            }
            else return false;
        }
        cout << "newNum: " << newNum << endl;
        return copy != newNum;
    }
};