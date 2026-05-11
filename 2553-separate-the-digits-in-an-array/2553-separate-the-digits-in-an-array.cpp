class Solution {
public:
    /*
        [13,25,83,77]
        7,7,3,8,5,2,3,1
        1 3 2 5 8 3 7 7
    */
    //TC: O(N*(LogD))
    //SC: O(1)
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i = n-1; i >= 0; i--){
            int num = nums[i];
            while(num){
                int digit = num % 10;
                num = num / 10;
                ans.push_back(digit);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};