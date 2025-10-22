/*
    n integer number 
    return any array containing unique integers such that they add up to 0
*/
class Solution {
public:
    vector<int> sumZero(int n) {
        int oe = n % 2;
        //if oe is 0 then even
        //else odd

        vector<int> ans;
        //even case
        if (oe == 0){
            for(int i = 1; i <= n/2; i++){
                ans.push_back(i);
                ans.push_back(-i);
            }
            return ans;
        }

        //odd case
        ans.push_back(0);
        for(int i = 1; i <= n/2; i++){
            ans.push_back(i);
            ans.push_back(-i);
        }
        return ans;
    }
};