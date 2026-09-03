class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int diff = INT_MAX;
        for(int i = 0; i < n-1; i++){
            int newDiff = arr[i+1]-arr[i];
            if(diff != INT_MAX && newDiff != diff){
                return false;
            }
            diff = newDiff;
        }

        return true;
    }
};