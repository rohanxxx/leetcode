class Solution {
public:
/*
    [ 0, 1, 2, 3, 4, 5, 6, 7]
    [73,74,75,71,69,72,76,73]
    [1,  1, 4, 2, 1, 1, 0, 0]
    [{73,0}-pop, {74,1}->pop, {75,2}, {71,3}->pop, {69,4}->pop, {72,5}->pop, {76,6},]
    [1,  1, 4, 2, 1, 1, 0, 0]
    [0,  1, 2, 3, 4, 5, 6, 7]
*/
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<pair<int, int>> stack;
        for(int i = 0; i < n; i++){
            if(stack.empty()){
                stack.push({temperatures[i], i});
                continue;
            }
            while(!stack.empty() && stack.top().first < temperatures[i]){
                pair<int, int> p = stack.top(); stack.pop();
                ans[p.second] = i-p.second;
            }
            stack.push({temperatures[i], i});
        }
        return ans;
    }
};