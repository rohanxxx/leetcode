/*
    Input: s = "abcdefg", k = 2
    Output: "bacdfeg"
     0 1 2 3 4 5 6
    "a b c d e f g"
     b a c d f e g


    //TC: O(N)
    //SC: O(1)
    for(i -> n && i += 2*k){
        left = i, right = min(i+k-1, n-1);
        while(left <= right){
            swap()
        }
    }

    return ans
*/
class Solution {
public:
    string reverseStr(string s, int k) {
        //TC: O(N)
        //SC: O(1)
        int n = s.length();
        for(int i = 0; i < n; i += 2*k){
            int left = i, right = min(i+k-1, n-1);
            while(left <= right){
                swap(s[left++], s[right--]);
            }
        }

        return s;
    }
};