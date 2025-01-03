class Solution {
public:
    int maxArea(vector<int>& height) {
        int mostWater = 0;
        int left = 0, right = height.size()-1;
        
        while(left < right){
            if(height[left] <= height[right]){
                mostWater = max(mostWater, height[left]*(right-left));
                left++;
                continue;
            }
            mostWater = max(mostWater, height[right]*(right-left));
            right--;
        }
        
        return mostWater;
    }
};