class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans=INT_MAX;
        for(int i=0;i<nums.size();++i)
        {
            int curr=0;
            for(int j=i;j<nums.size();++j)
            {
                curr+=nums[j];
                if((j-i+1)>=l && (j-i+1)<=r && curr>0)
                    ans=min(ans,curr);
            }
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};