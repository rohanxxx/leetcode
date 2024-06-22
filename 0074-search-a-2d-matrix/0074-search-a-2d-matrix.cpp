class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowSize = matrix.size();
        int columnSize = matrix[0].size();
        int left = 0, right = rowSize*columnSize-1;
        int mid, midElement;
        while(left <= right){
            mid = (left+right)/2;
            midElement = matrix[mid/columnSize][mid%columnSize];
            if(midElement == target) return true;
            if(midElement < target) left = mid+1;
            else right = mid-1;
        }
        return false;
    }
};