/* 
              0 1 2 4
    image = [[1,0,0],[1,0,1],[0,0,0]]
*/
class Solution {
public:
    void invert(vector<vector<int>>& image, int& r, int& c){
        if(image[r][c] == 0){
            image[r][c] = 1;
        }
        else{
            image[r][c] = 0;
        }
    }
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size(), m = image[0].size();
        //TC:O(N*M)
        for(int i = 0; i < n; i++){
            int left = 0, right = m-1;
            //TC: O(M)
            while(left < right){
                swap(image[i][left], image[i][right]);
                invert(image, i, left);
                invert(image, i, right);
                left++;
                right--;
            }

            if(m % 2 == 1){
                invert(image, i, left);
            }

        }

        return image;
    }
};