class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        for(auto it: queries){
            int xi = it[0];
            int yi = it[1];
            int ri = it[2];

            int count = 0;
            for(auto p: points){
                int x = p[0];
                int y = p[1];
                //(x-xi)+(y-yi) <= ri^2
                if(pow((x-xi), 2) + pow((y-yi), 2) <= pow(ri, 2)){
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};