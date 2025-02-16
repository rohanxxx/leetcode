class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[(arr[i]*2)] = i;
        }
        for(int i = 0; i < n; i++){
            if(mp.find(arr[i]) != mp.end()){
                if(mp[arr[i]] != i) return true;
            }
        }
        return false;
    }
};