class Solution {
public:
    string reverseVowels(string s) {
        int l = 0, r = (int)s.length()-1;
        while(l <= r){
            char c1 = tolower(s[l]);
            while(l <= r && c1 != 'a' && c1 != 'e' && c1 != 'i' && c1 != 'o' && c1 != 'u'){
                l++;
                c1 = tolower(s[l]);
            }

            char c2 = tolower(s[r]);
            while(l <= r && c2 != 'a' && c2 != 'e' && c2 != 'i' && c2 != 'o' && c2 != 'u'){
                r--;
                c2 = tolower(s[r]);
            }
            if(l <= r){
                swap(s[l], s[r]);
            }
            l++;
            r--;
        }

        return s;
    }
};