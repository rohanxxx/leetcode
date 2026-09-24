/*
    given string s and int k
    reverse the first k char of s and return the resulting string 


*/
class Solution {
public:
    string reversePrefix(string s, int k) {
        int n = s.length();

        int left = 0, right = k-1;
        while(left <= right && k <= n){
            swap(s[left], s[right]);
            left++;
            right--;
        }
        return s;
    }
};