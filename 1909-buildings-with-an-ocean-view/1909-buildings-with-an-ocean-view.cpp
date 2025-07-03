/*

                      0 1 2 3
    Input: heights = [4,2,3,1]
    Output: [0,2,3]


*/
class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();

        stack<int> stack;
        for(int i = 0; i < n; i++){
            while(!stack.empty() && heights[stack.top()] <= heights[i]){
                stack.pop();
            }
            stack.push(i);
        }

        int size = stack.size();
        vector<int> ans(size);
        while(!stack.empty()){
            ans[size-1] = stack.top();
            stack.pop();
            size--;
        }

        return ans;
    }
};