class Solution {
public:
    //Tc: O(N)
    //SC: O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        //first declare all the necessary variables
        unordered_map<int, int> hashmap;

        int n = nums.size();
        //0->n-1
        //TC: O(N)
        for(int i = 0; i < n; i++){
            int numsJ = target-nums[i];
            //if numsJ key exists in the hashmap
            //TC: O(1)
            if(hashmap.find(numsJ) != hashmap.end()){
                return {hashmap[numsJ], i};
            }
            hashmap.insert({nums[i], i});
        }

        return {};
    }
};