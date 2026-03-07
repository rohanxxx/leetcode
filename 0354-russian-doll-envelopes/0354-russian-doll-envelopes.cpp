/*
    [5,4],[6,4],[6,7],[2,3]
    [2,3] [5,4] [6,4] [6,7]

    secondD = 3,4,4,7
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size());
        
        int len = 0;

        for (int num : nums) {
            int i = lower_bound(dp.begin(), dp.begin() + len, num) - dp.begin();
            dp[i] = num;
            if (i == len) {
                len++;
            }
        }
        return len;
    }

    static bool comp(vector<int>& a, vector<int>& b){
        if(a[0] < b[0]) return true;
        if(a[0] > b[0]) return false;
        //if(a[0] == b[0])
        if(a[1] > b[1]) return true;
        else return false;
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // sort by increasing width, and if equal width then decreasing height
        /*sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });*/
        sort(envelopes.begin(), envelopes.end(), comp);
        /*for(auto it: envelopes){
            cout << "[" << it[0] << "," << it[1] << "] ";
        }*/
        vector<int> secondDim(envelopes.size());
        for (int i = 0; i < envelopes.size(); i++) {
            secondDim[i] = envelopes[i][1];
        }

        return lengthOfLIS(secondDim);
    }
};