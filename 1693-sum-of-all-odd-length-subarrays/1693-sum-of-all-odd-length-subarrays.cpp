class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {

        for(int i = 1; i < arr.size(); i++){
            arr[i] += arr[i-1];
        }

        int len = arr.size(), ans = 0;
        for(int left = 0; left < len; left++){
            for(int right = left; right < len; right++){
                int currSum = 0;
                if((right-left+1)%2==1){
                    if(left == 0) currSum = arr[right];
                    else currSum = arr[right] - arr[left-1];
                    ans += currSum;
                }
            }
        }
        return ans;
    }
};