class Solution {
public:
    int minChanges(string s) {
        int currentChar = s[0];
        int consecutiveChar = 0;
        int minChangesRequired = 0;

        for(int i = 0; i < s.length(); i++){
            if(s[i] == currentChar){
                consecutiveChar++;
                continue;
            }

            if(consecutiveChar % 2 == 0){
                consecutiveChar = 1;
            }
            else{
                consecutiveChar = 0;
                minChangesRequired++;
            }

            currentChar = s[i];
        }

        return minChangesRequired;
    }
};