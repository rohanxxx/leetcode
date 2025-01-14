class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int currentFar = 0;
        int currentEndIndex = 0;

        for(int i = 0; i < nums.size()-1; i++){
            currentFar = max(currentFar, i+nums[i]);
            if(i == currentEndIndex){
                jumps++;
                currentEndIndex = currentFar;
            }
        }

        return jumps;
    }
};