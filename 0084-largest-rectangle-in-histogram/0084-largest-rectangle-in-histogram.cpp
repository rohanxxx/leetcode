class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int maxArea = 0;
        stack<int> stack; stack.push(-1);
        for(int i = 0; i < heights.size(); i++){
            while(stack.top() != -1 && heights[stack.top()] >= heights[i]){
                int currentHeight = heights[stack.top()];
                stack.pop();
                int currentWidth = i - stack.top() - 1;
                maxArea = max(maxArea, currentHeight*currentWidth);
            }
            stack.push(i);
        }

        while(stack.top() != -1){
            int currentHeight = heights[stack.top()];
            stack.pop();
            int currentWidth = heights.size() - stack.top() - 1;
            maxArea = max(maxArea, currentHeight*currentWidth);
        }

        return maxArea;
    }
};