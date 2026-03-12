/*
    nums = [4,3,2,1], queries = [[1,3],[0,2]]

    0 1 2 3
    4 3 2 1
    0 0 0 0. 0
    0 1 0 0 -1
    1 0 0 -1-1
    1 2 2 1 0 -> difference arr

    diff arr - nums arr > 0 
*/
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        //TC: O(N+1)
        //SC: O(N+1)
        vector<int> transformer(n+1,0);

        //TC: O(M)
        for(auto q: queries){
            int l = q[0];
            int r = q[1];
            transformer[l] += 1;
            transformer[r+1] -= 1;
        }

        //TC: O(N)
        for(int i = 1; i < n; i++){
            transformer[i] += transformer[i-1];
        }

        //TC: O(N)
        for(int i = 0; i < n; i++){
            if(nums[i] > transformer[i]) return false;
        }

        return true;
    }
};