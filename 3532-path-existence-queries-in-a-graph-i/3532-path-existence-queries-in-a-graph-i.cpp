/*
     n -> number of nodes 0 - n-1
     nums of n sorted non-decreasing order
     int maxDiff

     undirected edge exists between nodes i and j
            if
     |nums[i] - nums[j]| <= maxDiff
                    0 1 2 3                             0     1     2.    3
     n = 4, nums = [2,5,6,8], maxDiff = 2, queries = [[0,1],[0,2],[1,3],[2,3]]

     1 - 2 - 3 

     0 

     1 2 
*/
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int prev = nums[0], count = 0;
        vector<int> groupCount(n, 0);
        for(int i = 0; i < n; i++){
            if(nums[i]-prev > maxDiff){
                count++;
            }
            groupCount[i] = count;
            prev = nums[i];
        }

        vector<bool> ans;
        for(auto it: queries){
            int u = it[0];
            int v = it[1];
            ans.push_back(groupCount[u] == groupCount[v]);
        }

        return ans;
    }
};