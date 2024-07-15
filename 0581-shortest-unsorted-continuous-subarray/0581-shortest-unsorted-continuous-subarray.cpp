class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int size = nums.size();
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        int start, end;
        for(int i = 0; i < size; i++){
            if(nums[i] != copy[i]){
                start = i;
                break;
            }
        }

        for(int i = size-1; i >= 0; i--){
            if(nums[i] != copy[i]) {
                end = i;
                break;
            }
        }

        if(end-start+1 > 0) return end-start+1;
        return 0;
    }
};