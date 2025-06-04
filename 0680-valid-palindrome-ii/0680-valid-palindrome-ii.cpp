/*
    1 2 3 2 1
     1 2 2 1
*/
class Solution {
public:
    bool isPalindrome(string& s, int left, int right){
        while(left < right){
            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        //int count = 0;
        int left = 0; 
        int right = s.length()-1;
        //TC:O(N)
        //SC: O(1)
        while(left < right){
            if(s[left] != s[right]){
                return isPalindrome(s, left, right-1) || isPalindrome(s, left+1, right);
            }
            left++;
            right--;
        }
        return true;
    }
};