class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {

        if (nums.size() == 1) return nums.back();
        vector<int> withoutDup;
        unordered_map<int, int> gain;

        for(auto &num: nums){
            if(!gain[num]) withoutDup.push_back(num);
            gain[num] += num;
        }

        if(withoutDup.size()==1) return gain[withoutDup.back()];
        
        sort(withoutDup.begin(), withoutDup.end());
       
        vector<int> dp(withoutDup.size(), 0);
        
        dp[0] = gain[withoutDup[0]];
        if(withoutDup[0] == withoutDup[1]-1) dp[1] = max(dp[0], gain[withoutDup[1]]);
        else dp[1] = dp[0] + gain[withoutDup[1]];

        for(int i = 2; i < withoutDup.size(); i++){
            if(withoutDup[i-1] == withoutDup[i]-1){
                dp[i] = max(dp[i-1], dp[i-2]+gain[withoutDup[i]]);
            }
            else{
                dp[i] = dp[i-1]+gain[withoutDup[i]];
            }
        }
        return dp.back();
    }
};