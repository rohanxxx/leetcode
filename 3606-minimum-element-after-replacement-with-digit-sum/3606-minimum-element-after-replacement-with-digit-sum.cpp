class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size(), opsCount = 0;
        vector<int> digitSum(n, 0);

        for(int i = 0; i < n; i++){
            int num = nums[i];
            while(num){
                int pop = num%10;
                num = num / 10;
                digitSum[i] += pop;
            }
        }
        int minSum = INT_MAX;    
        for(int sum: digitSum){
            minSum = min(minSum, sum);
        }
        return minSum;
    }
};