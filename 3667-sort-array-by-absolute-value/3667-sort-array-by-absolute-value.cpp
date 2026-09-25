/*
    rearrange elements of nums in non-decreasing order their abs value

    return any rearranged array that satisfies this condition.

    Input: nums = [3,-1,-4,1,5]
    Output: [-1,1,3,-4,5]
*/
class Solution {
public:
    static bool comp(int a, int b){
        return abs(a) < abs(b);
    }
    vector<int> sortByAbsoluteValue(vector<int>& nums) {
        /*int mini = INT_MAX, maxi = INT_MIN;
        for(auto it: nums){
            mini = min(mini, (int)abs(it));
            maxi = max(maxi, (int)abs(it));
        }

        vector<vector<int>> temp(maxi-mini+1);
        for(int it: nums){
            int index = (int)abs(it)-mini;
            temp[index].push_back(it);
        }

        vector<int> ans;
        for(vector<int> it: temp){
            for(auto i: it){
                ans.push_back(i);
            }
        }*/

        //vector<int> ans;
        sort(nums.begin(), nums.end(), comp);

        return nums;
    }
};