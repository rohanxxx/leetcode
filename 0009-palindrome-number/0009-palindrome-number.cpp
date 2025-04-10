class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        // cout << "INT_MAX: " << INT_MAX << endl;

        int cur = x, revert = 0;
        while(cur){
            int pop = cur % 10;
            if(revert == INT_MAX/10 && pop > 7) return 0;
            if(revert > INT_MAX/10) return 0;
            revert = (revert * 10 + pop);
            cur = cur / 10;
        }
        return x == revert;
    }
};