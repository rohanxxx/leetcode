/*
              0 1 2 3 4 5 6
    colors = [1,1,1,6,6,1,1]
    colors = [1,8,3,8,3]
*/
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int left = 0, right = colors.size()-1;
        int maxDist = 0;
        while(left < right){
            if(colors[left] != colors[right]){
                maxDist = max(maxDist, right-left);
                break;
            }
            left++;
        }
        left = 0; 
        right = colors.size()-1;
        while(left < right){
            if(colors[left] != colors[right]){
                maxDist = max(maxDist, right-left);
                break;
            }
            right--;
        }

        return maxDist;
    }
};