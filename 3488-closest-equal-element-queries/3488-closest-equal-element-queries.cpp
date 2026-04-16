class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> pos;

        int n = nums.size();
        for(int i = 0; i < n; i++){
            pos[nums[i]].push_back(i);
        }

        int m = queries.size();
        vector<int> ans(m, INT_MAX);

        for(int i = 0; i < m; i++){
            int num = nums[queries[i]];
            int currIndex = queries[i];

            if(pos[num].size() > 1){

                vector<int>& v = pos[num];
                int q = v.size();

                int lb = lower_bound(v.begin(), v.end(), currIndex) - v.begin();

                // previous occurrence (circular)
                int prevIdx = v[(lb - 1 + q) % q];
                if(prevIdx != currIndex){
                    int direct = abs(currIndex - prevIdx);
                    int circular = n - direct;
                    ans[i] = min(ans[i], min(direct, circular));
                }

                // next occurrence
                int nextIdx = v[(lb + 1) % q];
                if(nextIdx != currIndex){
                    int direct = abs(currIndex - nextIdx);
                    int circular = n - direct;
                    ans[i] = min(ans[i], min(direct, circular));
                }
            }

            if(ans[i] == INT_MAX){
                ans[i] = -1;
            }
        }

        return ans;
    }
};