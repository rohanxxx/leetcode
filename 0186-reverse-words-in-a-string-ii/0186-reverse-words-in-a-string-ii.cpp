class Solution {
public:
    void reverseWords(vector<char>& s) {
        int n = s.size();
        vector<char> reverse;
        string ts = "";
        for(int i = n-1; i >= 0; i--){
            if(s[i] != ' ') ts += s[i];
            
            if(s[i] == ' ' || i == 0){
                for(int j = ts.size()-1; j >= 0; j--){
                    reverse.push_back(ts[j]);
                }
                if(i != 0) reverse.push_back(' ');
                ts = "";
            }

            s.pop_back();
        }

        s = reverse;
    }
};