/*
    Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]

     0 1 2 3 4 5 6 7         0 1 2 3 4 5 6 7
    "c o d e l e e t"       [4,5,6,7,0,2,1,3]
*/
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans = s;
        int n = indices.size();
        for(int i = 0; i < n; i++){
            if(indices[i] != i){
                ans[indices[i]] = s[i];
            }
        }

        return ans;
    }
};