class Solution {
public:
    /*
        contraints are in between 1 <= n <= 100
        n = 3;
        arr = {1,2,3}
    */
    vector<string> simplifiedFractions(int n) {
        unordered_map<double, bool> visited;
        vector<string> ans;
        for(int i = 1; i <= n; i++){
            for(int j = i; j <= n; j++){
                int x = i;
                int y = j;
                double q = (double)x/(double)y;
                if(q > (double)0.0 && q < (double)1.0 && visited[q] == false){
                    visited[q] = true;
                    string temp = "";
                    temp += to_string(x);
                    temp += "/";
                    temp += to_string(y);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};