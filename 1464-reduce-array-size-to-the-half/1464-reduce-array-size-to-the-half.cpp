class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int arrSize = arr.size();
        unordered_map<int, int> mp;
        for(auto& array: arr){
            mp[array]++;
        }
        vector<int> occurences;
        for(auto it = mp.begin(); it != mp.end(); it++){
            occurences.push_back(it->second);
        }

        sort(occurences.begin(), occurences.end());

        int halfSize = arrSize/2;
        int sizeOfTheSet = 0, decSize = 0;
        for(int i = occurences.size()-1; i >= 0; i--){
            sizeOfTheSet++;
            decSize += occurences[i];
            if((arrSize-decSize) <= halfSize){
                return sizeOfTheSet;
            }
        }

        return 0;
    }
};