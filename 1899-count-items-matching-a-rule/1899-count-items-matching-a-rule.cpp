class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int count = 0;
        for(auto& it: items){
            if(ruleKey == "type" && it[0] == ruleValue){
                count++;
            }
            if(ruleKey == "color" && it[1] == ruleValue){
                count++;
            }
            if(ruleKey == "name" && it[2] == ruleValue){
                count++;
            }
        }

        return count;
    }
};