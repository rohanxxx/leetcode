class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        int groupCount = 0;
        vector<int> group(n,0);
        for(int i =1; i < n; i++){
            if(nums[i]-nums[i-1] > maxDiff){
                groupCount++;
            }
            group[i] = groupCount;
        }

        //now that we have grouped it based on the nodes that's over maxDif they are all seperate components based on their
        //groupCount number


        vector<bool> ans;
        for(auto q: queries){
            int u = q[0], v = q[1];
            ans.push_back(group[u] == group[v]);
        }
        return ans;
    }
};