class Solution {
public:
    char kthCharacter(int k) {
        string s = "a";
        string prev = "";

        while(s.length() < k){
            string current = "";
            for(char c: prev){
                if((1+(int)c) <= 122){
                    current += (1+(int)c);
                }
                else{
                    current += (((1+(int)c)-122)+96);
                }
            }
            if(prev == ""){
                current += "b";
            }
            current = (prev+current);
            s += current;
            prev = current;
        }
        return (char)s[k-1];
    }
};