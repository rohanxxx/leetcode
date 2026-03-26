/*
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
         3,3,5,

//Brute force TC: O(N*K)
               0 1  2  3 4 5 6 7
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3

 1x, 3x, -1x, -3x, 5

*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        for(int i = 0; i < k; i++){
            while(!dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }

        vector<int> ans;
        ans.push_back(nums[dq.front()]);

        int n = nums.size();
        for(int i = k; i < n; i++){
            if(k == i-dq.front()) dq.pop_front();
            while(!dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
            ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};