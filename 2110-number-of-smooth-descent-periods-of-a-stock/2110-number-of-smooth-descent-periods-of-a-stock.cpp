/*
                     0 1 2 3
    Input: prices = [3,2,1,4]
    Output: 7

    [3] [2] [1] [3,2] [2,1] [3,2,1]
    subArrSize : 1 2 3 1
    prefix     : 1 3 6 1

    Input: prices = [8,6,7,7]
    Output: 4

    8 6 7 7
*/
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        
        long long prefix = 1;
        long long subArrSize = 1;

        for(int i = 1; i < n; i++){
            if(prices[i]+1 == prices[i-1]){
                subArrSize = (long long)subArrSize + 1;
            }
            else{
                subArrSize = 1;
            }

            prefix = (long long)prefix + subArrSize;
        }

        return prefix;
    }
};