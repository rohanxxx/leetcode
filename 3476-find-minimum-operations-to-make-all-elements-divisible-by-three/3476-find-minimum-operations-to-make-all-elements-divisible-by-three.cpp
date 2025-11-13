class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int op = 0;
        for(auto num: nums){
            int rem = num % 3;
            if(rem) op += 1;
        }
        return op;
    }
};