class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int maxDistance = INT_MIN;
        int minSoFar, maxSoFar;
        for(int i = 0; i < arrays.size(); i++){
            if(i == 0){
                if(arrays[i].size() > 0){
                    minSoFar = arrays[i][0];
                    maxSoFar = arrays[i].back();
                }
                continue;
            }

            int temp1, temp2;
            if(arrays[i].size() > 0) {
                temp1 = arrays[i][0];
                maxDistance = max(maxDistance, abs(maxSoFar - temp1));
                temp2 = arrays[i].back();
                maxDistance = max(maxDistance, abs(temp2 - minSoFar)); 

                minSoFar = min(minSoFar, temp1);
                maxSoFar = max(maxSoFar, temp2);
            }
        }

        return maxDistance;
    }
};