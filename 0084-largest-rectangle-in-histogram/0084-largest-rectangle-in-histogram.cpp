class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stack;
        stack.push(-1);
        int maxArea = 0;

        for(int i = 0; i < heights.size(); i++){
            while(stack.top() != -1 && heights[stack.top()] >= heights[i]){
                int current_height = heights[stack.top()];
                stack.pop();
                int current_width = i - stack.top() - 1;
                maxArea = max(maxArea, current_height*current_width);
            }
            stack.push(i);
        }

        while(stack.top() != -1){
            int current_height = heights[stack.top()];
            stack.pop();
            int current_width = heights.size() - stack.top() - 1;
            maxArea = max(maxArea, current_height*current_width);
        }

        return maxArea;
    }
};