class Solution {
public:
    int maxRob(vector<int>& nums, int start, int end){
        deque<int> dp;
        dp.push_back(0);
        dp.push_back(0);
        for(int i = start; i < end; i++){
            dp.push_back(max(dp.front()+nums[i], dp.back()));
            dp.pop_front();
        }
        return dp.back();
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums.back();
        
        int index1 = maxRob(nums, 0, nums.size()-1);
        int index2 = maxRob(nums, 1, nums.size());
        
        return (int)max(index1, index2);
    }
};