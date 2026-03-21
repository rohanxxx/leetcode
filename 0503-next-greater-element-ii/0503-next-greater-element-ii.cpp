/*
     0 1 2 3 4 5
    [1,2,1 1 2 1
     2

    2 2
*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        stack<int> stack;
        for(int i = 0; i < n*2; i++){
            while(!stack.empty() && nums[stack.top()] < nums[i%n]){
                ans[stack.top()] = nums[i%n];
                stack.pop();
            }
            stack.push(i%n);
        }
        return ans;
    }
};