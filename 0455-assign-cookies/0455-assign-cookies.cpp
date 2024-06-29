class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int contentChildren = 0;
        int cookieSize = 0;

        while(cookieSize < s.size() && contentChildren < g.size()){
            if(s[cookieSize] >= g[contentChildren]) contentChildren++;
            cookieSize++;
        }
        return contentChildren;
    }
};