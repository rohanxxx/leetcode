class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size()-1;
        int maxVolume = INT_MIN;
        while(left < right){
            int currentVolume = (right-left)* (int)min(height[left], height[right]);
            maxVolume = max(maxVolume, currentVolume);
            if(height[left] <= height[right]) left++;
            else right--;
        }
        return maxVolume;
    }
};