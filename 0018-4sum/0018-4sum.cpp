/*

Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

-2 -1 0 0 1 2

*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> set;

        //TC: O(NlogN)
        //SC: O(N)
        sort(nums.begin(), nums.end());

        //TC: O(N^2)
        //SC: O(N)
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                int lo = j+1; 
                int hi = n-1;
                while(lo < hi){
                    long long sum = static_cast<long long> (nums[i]) + nums[j] + nums[lo] + nums[hi];
                    if(sum == target){
                        set.insert({nums[i], nums[j], nums[lo++], nums[hi]});
                    }
                    else if(sum < target){
                        lo++;
                    }
                    else{
                        hi--;
                    }
                }
            }
        }

        return vector<vector<int>> (set.begin(), set.end());
    }
};