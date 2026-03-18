/*
    5/2 = 2
    0 1 2 3 4
    odd left <= right

    6/2 = 3
    0 1 2 3 4 5
    even left < right
*/
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int l = 0, r = n-1;

        if(n % 2){
            //odd case
            while(l <= r){
                swap(s[l], s[r]);
                l++; r--;
            }
        }
        else{
            while(l < r){
                swap(s[l], s[r]);
                l++; r--;
            }
        }

    }
};