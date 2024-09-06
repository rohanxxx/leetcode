class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int> mp;
        
        int n = arr.size();
        
        for(int i = 0; i < n; i++) mp[arr[i]]++;
        
        int count = 0;
        for(int i = 0; i < n; i++){
            int x = arr[i];
            if(mp[x+1] > 0){
                count++;
                // mp[x+1]--;
            }
        }

        return count;
    }
};