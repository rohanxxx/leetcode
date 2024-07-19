class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int x = INT_MIN, operationCount = 0;
        for(auto& num: nums){
            if(num > 0){
                if(x < num){
                    operationCount++;
                    x = num;
                }
            }
            if(nums.back() == x) return operationCount;
        }

        return 0;

    }
};