class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        //if(n < 2) return true;
        
        int capitalCount = 0;
        bool firstCapital = false;
        
        //tc: O(N)
        //sc: O(1)
        for(int i = 0; i < n; i++){
            if(i == 0){
                if(toupper(word[i]) == word[i]){
                    capitalCount++;
                    firstCapital = true;
                }
            }
            else if(toupper(word[i]) == word[i]){
                capitalCount++;
            }
        }
        if(capitalCount == 1 && firstCapital == true) return true;
        if(capitalCount == 0) return true;
        return capitalCount == n;
    }
};