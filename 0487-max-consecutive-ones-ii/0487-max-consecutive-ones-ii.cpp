class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int lastZeroAt = -1;
        int flipZero = INT_MIN;
        int maxSeq = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                maxSeq = max(maxSeq, i - lastZeroAt);
                continue;
            }

            if(flipZero != INT_MIN){
                lastZeroAt = flipZero;
                flipZero = i;
                maxSeq = max(maxSeq, i - lastZeroAt);
                continue;
            }

            flipZero = i;
            maxSeq = max(maxSeq, i - lastZeroAt);
        }

        return maxSeq;
    }
};