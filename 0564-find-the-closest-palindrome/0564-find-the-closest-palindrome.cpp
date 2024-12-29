class Solution {
public:
    long halfPalindrome(long left, bool even){
        long res = left;
        if(!even) left = left/10;
        while(left > 0){
            res = res*10 + left%10;
            left /= 10;
        }

        return res;
    }
    string nearestPalindromic(string n) {
        int len = n.size(), i = 0;
        
        if(len % 2 == 0) i = len/2-1;
        else i = len/2;

        long firstHalf = stol(n.substr(0, i+1));

        vector<long> v;
        v.push_back(halfPalindrome(firstHalf, len%2==0));
        v.push_back(halfPalindrome(firstHalf+1, len%2==0));
        v.push_back(halfPalindrome(firstHalf-1, len%2==0));
        v.push_back((long)pow(10, len-1)-1);
        v.push_back((long)pow(10, len)+1);

        long diff = LONG_MAX, res = 0, nl = stol(n);
        for(auto cand: v){
            if(cand == nl) continue;
            if(abs(cand-nl) < diff){
                diff = abs(cand-nl);
                res = cand;
            }
            else{
                if(abs(cand-nl) == diff) res = min(res, cand);
            }
        }

        return to_string(res);
    }
};