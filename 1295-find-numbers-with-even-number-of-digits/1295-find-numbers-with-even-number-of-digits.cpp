class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evenCount = 0;
        for(auto num: nums){
            int x = num;
            int count = 0;
            while(x){
                int digit = x % 10;
                x = x/10;
                count++;
            }
            if(count % 2 == 0){
                evenCount++;
            }
        }
        return evenCount;
    }
};