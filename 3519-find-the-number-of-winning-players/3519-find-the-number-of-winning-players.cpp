class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
         unordered_map<int,unordered_map<int,int>>mp;
        
        for(vector<int> v: pick){
            mp[v[0]][v[1]]++;
        }
        
        int count = 0;
        
        for(auto i : mp){
            int maxi =0;
            int player = i.first;
            
            for(auto j : i.second) {
                maxi = max(maxi,j.second);
            }
            if(player < maxi) {
                count++;
            }
        }
        return count;
    }
};