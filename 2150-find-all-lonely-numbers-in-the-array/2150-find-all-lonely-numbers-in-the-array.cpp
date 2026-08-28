/*
    number x is lonely when it appears only once
    and no adj numbers appear in the array (x+1 and x-1)

    route#1 -> sort it TC: (NlogN) TC: O(N)
    route#2 -> use set TC: O(N) SC: O(N)
*/
class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        unordered_map<int, int> map;

        int n = nums.size();
        for(int i = 0; i < n; i++){
            map[nums[i]]++;
        }

        vector<int> ans;
        for(auto num: nums){
            if(!(map[num] > 1 || map.count(num+1) || map.count(num-1))){
                ans.push_back(num);
            }
        }

        return ans;
    }
};