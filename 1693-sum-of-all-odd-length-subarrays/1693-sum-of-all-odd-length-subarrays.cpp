class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int len = arr.size(), ans = 0;
        for(int left = 0; left < len; left++){
            for(int right = left; right < len; right++){
                int currSum = 0;
                if((right-left+1)%2==1){
                    for(int i = left; i < right+1; i++){
                        currSum += arr[i];
                    }
                    ans += currSum;
                }
            }
        }
        return ans;
    }
};