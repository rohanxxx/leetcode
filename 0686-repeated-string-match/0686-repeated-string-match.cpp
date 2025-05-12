class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int count = 1;
        string s = a;
        while(s.length() < b.length()){
            s += a;
            count++;
        }

        if(s.find(b) != string::npos){
            return count;
        }

        s += a;
        count++;
        if(s.find(b) != string::npos){
            return count;
        }

        return -1;
    }
};