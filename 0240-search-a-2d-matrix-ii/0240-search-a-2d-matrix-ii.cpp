class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();      //row size
        int m = matrix[0].size();   //col size
        for(int i = 0; i < n; i++){
            //we do binary search here row by row
            int left = 0;
            int right = m-1;
            //cout << "i: " << i << endl;
            while(left <= right){
                int mid = (left+right)/2;
                //cout << "mid: " << mid << endl;
                if(matrix[i][mid] == target) return true;
                if(matrix[i][mid] < target) left = mid+1;
                else right = mid-1;
            }
        }
        return false;
    }
};