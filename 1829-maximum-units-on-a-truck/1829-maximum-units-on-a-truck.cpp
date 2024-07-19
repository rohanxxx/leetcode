class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        for(auto& box: boxTypes){
            swap(box[0], box[1]);
        }

        sort(boxTypes.begin(), boxTypes.end());
        reverse(boxTypes.begin(), boxTypes.end());
        
        for(auto& box: boxTypes){
            cout << "[" << box[0] << "," << box[1] << "] ";
        }
        cout << endl;
        
        int totalUnit = 0;
        for(auto& box: boxTypes){
            int numBoxes = box[1];
            int unit = box[0];
            if(numBoxes <= truckSize){
                totalUnit += (numBoxes*unit);
                truckSize -= numBoxes;
            }
            else{
                if(truckSize != 0){
                    totalUnit += (truckSize*unit);
                    truckSize -= truckSize;
                }
            }
            if(truckSize == 0) return totalUnit;
        }
        return totalUnit;
    }
};