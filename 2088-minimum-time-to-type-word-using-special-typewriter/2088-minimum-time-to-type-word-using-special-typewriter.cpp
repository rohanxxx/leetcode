class Solution {
public:
    int minTimeToType(string word) {
        char p = 'a';
        int count = word.size();
        for(char c: word){
            count += min(abs(c-p), 26-abs(c-p));
            p = c;
        }
        return count;
    }
};