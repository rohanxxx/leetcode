class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //SC: O(N)
        unordered_map<int, int> hashmap; //{key-> nums[i], val-> i}

        int n = nums.size();
        //O(N*1*1) = O(N)
        for(int i = 0; i < n; i++){
            //nums[i]+nums[j] == target
            //nums[j] = target - nums[i]
            int numsJ = target - nums[i];
            if(hashmap.find(numsJ) != hashmap.end()){
                return {hashmap[numsJ], i};
            }
            hashmap.insert({nums[i], i});
        }
        return vector<int>();
    }
};