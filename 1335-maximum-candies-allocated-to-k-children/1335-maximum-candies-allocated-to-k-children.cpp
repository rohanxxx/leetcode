class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int maxElement = INT_MIN;
        for(int num: candies){
            maxElement = max(maxElement, num);
        }

        int maxPile = 0;
        int left = 1, right = maxElement;
        while(left <= right){
            int i = (left+right)/2;
            long long child = k;
            for(int num: candies){
                child -= (num/i);
                if(child <= 0){
                    maxPile = max(maxPile, i);
                    break;
                }
            }

            if(child <= 0) left = i+1;
            else right = i-1;
        }

        return maxPile;
    }
};