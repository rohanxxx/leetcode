class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        //TC: O(N*N)
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(words[i].size() <= words[j].size()){
                    bool check = true;

                    string prefix = words[j].substr(0, words[i].size());
                    if(words[i] != prefix){
                        check = false;
                    }

                    string suffix = words[j].substr(words[j].size()-words[i].size(), words[i].size());
                    if(words[i] != suffix){
                        check = false;
                    }

                    if(check == true) count++;
                }
            }
        }

        return count;
    }
};