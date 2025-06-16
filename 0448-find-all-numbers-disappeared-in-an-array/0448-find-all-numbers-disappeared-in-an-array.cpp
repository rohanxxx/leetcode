/*
               1 2 3 4 5 6 7 8
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> map(n, 0);
        for(auto& num: nums){
            map[num-1]++;
        }
        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(map[i] == 0) ans.push_back(i+1);
        }
        return ans;
    }
};