class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        stack<int> stack;
        for(int i = 0; i <= n; i++){
            while(!stack.empty() && (i == n || heights[stack.top()] >= heights[i])){
                int curHeight = heights[stack.top()]; stack.pop();
                
                int curWidth = 0;
                if(!stack.empty()) curWidth = i - stack.top() - 1;
                else curWidth = i;
                
                int curArea = curHeight * curWidth;
                maxArea = max(maxArea, curArea);
            }
            stack.push(i);
        }  
        return maxArea; 
    }
};