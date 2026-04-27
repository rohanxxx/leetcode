/*
    heights = [2,1,5,6,2,3]
     0 1 2 3 4 5
    [2,1,5,6,2,3]
    2x 1 5x 6x 2 3

     0 1 2 3
    [2,1,2]
     0 1 2 3 4 5
    [4,2,0,3,2,5]
    4x 2

    max-> 4
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stack;
        
        int maxArea = 0;
        int n = heights.size();
        for(int i = 0; i < n+1; i++){
            while(!stack.empty() && (i == n || heights[stack.top()] > heights[i])){
                int height = heights[stack.top()]; stack.pop();
                int currWidth = 0;
                
                if(!stack.empty()) currWidth = i-stack.top()-1;
                else currWidth = i;
        
                maxArea = max(maxArea, currWidth*height);
            }
            stack.push(i);
        }

        return maxArea;
    }
};