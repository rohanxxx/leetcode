class Solution {
public:
    int countValidSelections(vector<int>& nums)
    {
        vector<int> leftSum(nums.size(),0);
        vector<int> rightSum(nums.size(),0);
        for(int i=1;i<nums.size();i++)
        {
            leftSum[i]=leftSum[i-1]+nums[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--)
        {
            rightSum[i]=rightSum[i+1]+nums[i+1];
        }
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                if(leftSum[i]==rightSum[i])
                {
                    ans+=2;
                }
                else if(abs(leftSum[i]-rightSum[i])==1)
                {
                    ans+=1;
                }
            }
        }
        return ans;
    }
};