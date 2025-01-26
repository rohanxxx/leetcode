class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size = temperatures.size();
        vector<int> ans(size, 0);
        stack<vector<int>> stack;

        for(int i = 0; i < size; i++){
            while(!stack.empty() && (temperatures[i] > stack.top()[0])){
                ans[stack.top()[1]] = i - stack.top()[1];
                stack.pop();
            }
            stack.push({temperatures[i], i});
        }

        return ans;
    }
};