class Solution {
public:
    vector<int> countBits(int n) {
        //SC: O(n)
        vector<int> ans;
        //TC: O(n*32)
        for(int j = 0; j <= n; j++){
            int count = 0;
            for(int i = 0; i < 32; i++){
                if(j & (1 << i)){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};