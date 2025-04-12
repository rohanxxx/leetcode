class Solution {
public:
    bool solve(int ind,vector<int>& nums, vector<vector<int>>& queries){
        int n = nums.size();
        vector<int> q (n+1, 0);
        
        for(int i=0;i<=ind;i++){
            q[queries[i][0]] += queries[i][2];
            q[queries[i][1]+1] -= queries[i][2];
        }
        
        vector<int> prefix(n);
        for(int i = 0; i < n; i++){
            if(i == 0) prefix[0] = q[0];
            else prefix[i]=prefix[i-1]+q[i];
            
            if(prefix[i] < nums[i]) return false;
        }
        return true;
    }
    
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        bool f = true;
        
        for(auto it: nums) if(it != 0) f = false;

        if(f) return 0;
        
        int s = 0, e = queries.size()-1;
        int ans =- 1;
        
        //trying to make ans till an index 
        while(s <= e){
            int m = s+(e-s)/2;
            if(solve(m,nums,queries)){
                ans=m+1;e=m-1;
            }
            else s=m+1;
        }
        return ans;
    }
};