class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> prefixes;
        for(int val: arr1){
            while(!prefixes.count(val) && val > 0){
                prefixes.insert(val);
                val /= 10;
            }
        }

        int longestPrefixCount = 0;
        for(int val: arr2){
            // it will fail when the val is found
            while(!prefixes.count(val) && val > 0){
                val /= 10;
            }

            // if val is found then execute this
            if(val > 0){
                string str = to_string(val);
                longestPrefixCount = max(longestPrefixCount, (int)str.length());
            }
        }

        return longestPrefixCount;
    }
};