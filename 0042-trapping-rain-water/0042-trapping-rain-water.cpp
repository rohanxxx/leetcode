class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> leftMax(size, 0), rightMax(size, 0);
        for(int i = 1; i < size; i++){
            leftMax[i] = max(leftMax[i-1], height[i-1]);
        }
        for(int i = size-2; i >= 0; i--){
            rightMax[i] = max(rightMax[i+1], height[i+1]);
        }

        int trapWater = 0;
        for(int i = 0; i < size; i++){
            int dif = min(leftMax[i], rightMax[i])-height[i];
            if(dif > 0){
                trapWater += dif;
            }
        }

        return trapWater;
    }
};