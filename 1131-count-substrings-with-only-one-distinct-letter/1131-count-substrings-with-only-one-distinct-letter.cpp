class Solution {
public:
    int countLetters(string s) {
        vector<int> v;
        int count=1,ans=0;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1]) count++;
            else{
                v.push_back(count);
                count=1;
            }
        }
        v.push_back(count);

        for(auto x:v) ans+=(x*(x+1))/2;

        return ans;
    }
};