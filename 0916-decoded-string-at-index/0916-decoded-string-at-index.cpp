class Solution {
public:
    string decodeAtIndex(string s, int k) {
        long size = 0;
        int len = s.length();
        for(int i = 0; i < len; i++){
            if(isdigit(s[i])){
                size *= (int)(s[i]-'0');
            }
            else{
                size++;
            }
        }

        for(int i = len-1; i >= 0; i--){
            k %= size;
            if(k == 0 && isalpha(s[i])){
                return (string) ""+s[i];
            }
            if(isdigit(s[i])){
                size /= (int)(s[i]-'0');
            }
            else{
                size--;
            }
        }
        return "";
    }
};