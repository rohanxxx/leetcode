class Solution {
public:
    string ans;
    void backtrack(unordered_set<string>& set, int& n, string& cur){
        if(cur.size() == n){
            if(set.find(cur) == set.end()){
                ans = cur;
            }
            return;
        }

        for(auto& it: {"0", "1"}){
            cur += it;
            backtrack(set, n, cur);
            cur.pop_back();
        }

        return;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        ans = "";
        int n = nums.size();
        unordered_set<string> set(nums.begin(), nums.end());

        string cur = "";
        backtrack(set, n, cur);
        return ans;
    }
};