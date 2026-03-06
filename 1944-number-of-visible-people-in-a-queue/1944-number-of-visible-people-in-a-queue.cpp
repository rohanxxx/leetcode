/*  
                0 1 2 3  4 5
    heights = [10,6,8,5,11,9]
                3,1,2,1, 1,0
                9x,11,5x,8,6

    heights = [5,1,2,3,10]
               4,1,1,1,0
               10,3x,2x,1x 
*/
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n, 0);
        stack<int> stack; //stores index
        for(int i = n-1; i >= 0; i--){
            while(!stack.empty() && heights[i] > heights[stack.top()]){
                ans[i]++;
                stack.pop();
            }
            if(!stack.empty()){
                ans[i]++;
            }
            stack.push(i);
        }
        return ans;
    }
};