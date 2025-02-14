class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int count = 0;
        for(int i = 0; i < s.length(); i++){
            int zeros = 0, ones = 0;
            for(int j = i; j < s.length(); j++){
                if(s[j] == '0'){
                    zeros++;
                }
                else{
                    ones++;
                }
                
                if(zeros <= k || ones <= k){
                    count++;
                }
                if(zeros > k && ones > k){
                    break;
                }
            }
        }
        return count;
    }
};