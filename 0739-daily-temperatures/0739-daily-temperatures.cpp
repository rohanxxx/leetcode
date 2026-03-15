/*
      0  1  2  3. 4. 5. 6. 7 
    [73,74,75,71,69,72,76,73]
     1   1. 1. 2. 1 1. 0. 0

     0x, 

     ans[stack.top()] = i - stack.top();
     stack.pop();
     stack.push(i);

     for(i -> n){
        for(j = i+1 -> n){
            if(nums[i] < nums[j]){
                ans[i] = j-i;
                break;
            }
        }
     }
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> stack;
        int n = temperatures.size();
        
        vector<int> ans(n, 0);
        for(int i = 0; i < n; i++){
            while(!stack.empty() && temperatures[stack.top()] < temperatures[i]){
                ans[stack.top()] = i-stack.top();
                stack.pop();
            }
            stack.push(i);
        }

        return ans;
    }
};