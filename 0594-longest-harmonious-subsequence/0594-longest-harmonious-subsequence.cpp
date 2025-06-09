/*
    nums = [1,3,2,2,5,2,3,7]
    1 2 2 2 3 3 5 7
    for(i = min+1; i <= max; i++){

    }
*/
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<long long, int> map;
        int len = 0;
        sort(nums.begin(), nums.end());
        for(auto num: nums){
            map[num]++;
            if(map[num] > 0 && map[num-1] > 0){
                len = max(len, map[num]+map[num-1]);
            }
        }
        return len;
    }
};