class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        /*
        if(nums.empty()) return 0;
        vector<int> subArr;
        subArr.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];
            if(num > subArr.back()){
                subArr.push_back(num);
            }
            else{
                auto it = lower_bound(subArr.begin(), subArr.end(), num);
                *it = num;
                // cout << "num: " << num << endl;
                for(auto arr: subArr){
                    cout << arr << " ";
                }
                cout << endl;
            }
        }
     
        return subArr.size();*/
        if (nums.empty()) return 0;

        std::vector<int> dp(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }

        return *std::max_element(dp.begin(), dp.end());
    }
};