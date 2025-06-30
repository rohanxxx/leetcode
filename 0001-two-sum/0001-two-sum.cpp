class Solution {
public:
    //TC: O(N)
    //SC: O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        //{key->nums[j], val-> index of nums[j]}
        //SC: O(N) at max in worstcase
        unordered_map<int, int> hashmap;

        int n = nums.size();
        //TC: O(N*1*1) = O(N)
        for(int i = 0; i < n; i++){
            int numsJ = target-nums[i];
            //checks whether numsJ exists in my hashmap or not
            //if exists then go inside the if loop
            if(hashmap.find(numsJ) != hashmap.end()){
                return {hashmap[numsJ], i};
            }
            hashmap.insert({nums[i], i});
        }
        return vector<int>();
    }
};