/*
    Input: plants = [2,2,3,3], capacity = 5
    Output: 14

              0 1 2 3
    plants = [2,2,3,3]

    for(int i = 0; i < n; i++){
        if(nums[i] <= curCap){
            curCap -= nums[i];
            stepCount++;
        }
        else{
            //going backwards
            stepCount += (i-1-river);
            curCap = capacity - nums[i];

            //from river to current position steps
            stepCount += (i+1);
        }
    }
*/
class Solution {
public:
    int wateringPlants(vector<int>& nums, int capacity) {
        int n = nums.size();
        int curCap = capacity;
        int river = -1, stepCount = 0;
        for(int i = 0; i < n; i++){
            if(nums[i] <= curCap){
                curCap -= nums[i];
                stepCount++;
            }
            else{
                //going backwards
                stepCount += (i-1-river);
                curCap = capacity - nums[i];

                //from river to current position steps
                stepCount += (i+1);
            }
        }

        return stepCount;
    }
};