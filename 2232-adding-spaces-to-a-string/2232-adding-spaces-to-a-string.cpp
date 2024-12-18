class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int size = s.length();
        int it = 0;
        string ans = "";

        for(int i = 0; i < size; i++){

            if(it < spaces.size()){
                if(i == spaces[it]){
                    it++;
                    ans += " ";
                }
            }

            ans += s[i];
        }

        return ans;
    }
};