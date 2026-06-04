/*
    1 2 3 2 5
*/
class Solution {
public:
    int totalWaviness(int num1, int num2) {
    
        int count = 0;
        for(int i = num1; i <= num2; i++){
            int num = i;
            if(num < 100){
                continue;
            }

            deque<int> dq;
            while(num){
                int digit = num % 10;
                num = num/10;
                
                if(dq.size() == 2){
                    //then compare
                    if((dq.front() > digit && dq.front() > dq.back()) || (dq.front() < digit && dq.front() < dq.back())){
                        count++;
                    }
                }

                dq.push_front(digit);
                while(dq.size() > 2){
                    dq.pop_back();
                }
            }
        }

        return count;
    }
};