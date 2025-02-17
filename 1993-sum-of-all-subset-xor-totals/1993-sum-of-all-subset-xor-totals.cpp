class Solution {
public:
    int sum;
    void backtrack(int index, int cur, int& n, vector<int>& nums){
        for(int i = index; i < n; i++){
            int temp = cur ^ nums[i];
            sum += temp;
            backtrack(i+1, temp, n, nums);
        }
    }
    int subsetXORSum(vector<int>& nums) {
        sum = 0;
        int n = nums.size();
        backtrack(0, 0, n, nums);
        return sum;
    }
};