class Solution {
public:
    int largestRectangleArea(int r, vector<vector<int>>& heights) {
        stack<int> stack;
        
        int maxArea = 0;
        int n = heights[r].size();
        for(int i = 0; i < n+1; i++){
            while(!stack.empty() && (i == n || heights[r][stack.top()] > heights[r][i])){
                int height = heights[r][stack.top()]; stack.pop();
                
                int currWidth = 0;
                if(!stack.empty()) currWidth = i-stack.top()-1;
                else currWidth = i;
        
                maxArea = max(maxArea, currWidth*height);
            }
            stack.push(i);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> heights(n, vector<int>(m, 0));
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                if(matrix[r][c] == '1'){
                    heights[r][c] = 1;
                }
            }
        }

        for(int c = 0; c < m; c++){
            for(int r = 0; r < n; r++){
                if(r == 0){
                    continue;
                }
                if(heights[r][c] > 0){
                    heights[r][c] += heights[r-1][c]; 
                }
            }
        }

        int maxRectangle = 0;
        for(int r = 0; r < n; r++){
            maxRectangle = max(maxRectangle, largestRectangleArea(r, heights));
        }

        return maxRectangle;
    }
};