class Solution {
public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        vector<int> ans(maxLength+1, 0);
        ans[0] = 1;

        int mod = 1e9+7;
        for(int i = 1; i <= maxLength; i++){
            int temp = 0;
            if(i >= oneGroup) temp += ans[i-oneGroup];
            temp %= mod;
            if(i >= zeroGroup) temp += ans[i-zeroGroup];
            temp %= mod;
            ans[i] = temp; 
        }

        int res = 0;
        for(int i = minLength; i <= maxLength; i++){
            res += ans[i];
            res %= mod;
        }
        return res;
    }
};