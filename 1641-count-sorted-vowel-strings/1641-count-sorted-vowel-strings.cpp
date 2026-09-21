/*
    return the number of strings of len n that consists only of vowels 
    ans are lexicographically sorted

    n = 2

    aa ae ai
*/
class Solution {
public:
    int countVowelStrings(int n) {
        return ((n+4)*(n+3)*(n+2)*(n+1))/24;
    }
};