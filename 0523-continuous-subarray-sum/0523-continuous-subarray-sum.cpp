class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int prefixMod = 0;
        unordered_map<int, int> modSeen;
        modSeen[prefixMod] = -1;
        for(int i = 0; i < nums.size(); i++){
            prefixMod = (nums[i]+prefixMod)%k;
            if(modSeen.find(prefixMod) != modSeen.end()){
                if(i-modSeen[prefixMod] >= 2) return true;
            }
            else modSeen[prefixMod] = i; 
        }
        return false;
    }
};