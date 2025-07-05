class Solution {
public:
    //TC: O(N)
    //SC: O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        //SC: O(N)
        unordered_map<int, int> hashmap;
        int n = nums.size();
        //TC: O(N)
        for(int i = 0; i < n; i++){
            int numsJ = target - nums[i];
            //check numsJ key exists in the hashmap or not
            //TC: O(1)
            if(hashmap.find(numsJ) != hashmap.end()){
                return {hashmap[numsJ], i};
            }
            //TC: O(1)
            hashmap.insert({nums[i], i});
        }
        return {};
    }
};