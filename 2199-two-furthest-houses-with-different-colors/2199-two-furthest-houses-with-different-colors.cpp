class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxDistance = INT_MIN;
        int left = 0, right = colors.size()-1;
        while(left < right){
            if(colors[left] != colors[right]){
                maxDistance = max(maxDistance, right-left);
                break;
            }
            right--;
        }

        left = 0, right = colors.size()-1;
        while(left < right){
            if(colors[left] != colors[right]){
                maxDistance = max(maxDistance, right-left);
                break;
            }
            left++;
        }

        return maxDistance;
    }
};