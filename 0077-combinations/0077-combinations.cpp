/*
 20^2 = 10^6 < 10^8
 {1,2,3,4}
 1 2
 1 3
 1 4
 2 1/
 2 3
 2 4
 3 1/
 3 2
 3 4
*/
class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    void backtrack(int& n, int& k, int index){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        for(int i = index; i <= n; i++){
            temp.push_back(i);
            backtrack(n, k, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtrack(n, k, 1);
        /*vector<vector<int>> finalAns;
        for(set<int> it: ans){
            vector<int> t(it.begin(), it.end());
            finalAns.push_back(t);
        }*/
        return ans;
    }
};