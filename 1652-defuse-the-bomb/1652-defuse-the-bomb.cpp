/*
    if k > 0 replace the ith number with the sum of the next k numbers
    if k < 0 replace the ith number with the sum of the previous - k numbers
    if k == 0 replace the ith number with 0

    code is circular  next element of code[n-1] is code[0]

    [2,6,15,18]
*/
class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);
        if(k > 0){
            int sum = 0;
            for(int i = 1; i < k+1; i++){
                sum += code[i];
            }
            ans[0] = sum;
            for(int i = 1; i < n; i++){
                sum += code[(i+k)%n];
                sum -= code[i];
                ans[i] = sum;
            }
        }
        if(k < 0){
            int sum = 0;
            for(int i = -1; i >= k; i--){
                sum += code[(i+n)%n];
            }
            ans[0] = sum;
            for(int i = 1; i < n; i++){
                sum -= code[((i-1+k) % n + n) % n];
                sum += code[i-1];
                ans[i] = sum;
            }
        }

        return ans;
    }
};