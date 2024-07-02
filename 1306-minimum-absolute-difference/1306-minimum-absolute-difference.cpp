class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minDif = INT_MAX, i;
        sort(arr.begin(), arr.end());
        for(i = 0; i < arr.size()-1; i++){
            minDif = min(minDif, arr[i+1]-arr[i]);
        }

        vector<vector<int>> res;
        for(i = 0; i < arr.size()-1; i++){
            if(arr[i+1]-arr[i] == minDif) res.push_back({arr[i], arr[i+1]}); 
        }

        return res;
    }
};