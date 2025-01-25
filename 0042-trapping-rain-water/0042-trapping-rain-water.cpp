class Solution {
public:
    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> left(size, 0), right(size, 0);
        for(int i = 1; i < size; i++){
            left[i] = max(left[i-1], height[i-1]);
        }
        for(int i = size-2; i >= 0; i--){
            right[i] = max(right[i+1], height[i+1]);
        }

        int trapWater = 0;
        for(int i = 0; i < size; i++){
            int difference = min(right[i], left[i]) - height[i];
            if(difference > 0) trapWater += difference;
        }

        return trapWater;
    }
};