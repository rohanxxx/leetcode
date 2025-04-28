class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        deque<int> dq; 
        vector<int> ans;
        
        for(int i = 0; i < k; i++){
            while(!dq.empty() && nums[i] > nums[dq.back()]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        
        ans.push_back(nums[dq.front()]);
        
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