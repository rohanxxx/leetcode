class Solution {
public: 
    //TC: O(D)
    int elementSum(int num){
        int sum = 0;
        while(num > 0){
            int digit = num % 10;
            num = num / 10;
            sum += digit;
        }

        return sum;
    }
    int minElement(vector<int>& nums) {

        int minSum = INT_MAX;
        //TC: O(N*D)
        for(auto num: nums){
            int sum = elementSum(num);
            minSum = min(sum, minSum);
        }

        if(minSum == INT_MAX){
            return 0;
        }

        return minSum;
    }
};