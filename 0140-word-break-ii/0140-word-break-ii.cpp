/*
    Input: s = "catsanddog", wordDict = ["cat","cats","and","sand","dog"]
    Output: ["cats and dog","cat sand dog"]
    unordered_set<string> set(wordDict.begin(), wordDict.end());
*/
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        
        int n = s.length();
        //{index sentence}
        queue<pair<int, string>> q;
        q.push({0, ""});
        vector<string> ans;
        while(!q.empty()){
            int index = q.front().first;
            string sentence = q.front().second;

            q.pop();

            if(index == n){
                sentence.pop_back();
                ans.push_back(sentence);
            }
            for(int i = index; i < n; i++){
                string word = s.substr(index, i-index+1);
                if(set.find(word) != set.end()){
                    string newSentence = sentence + word + " ";
                    q.push({i+1, newSentence});
                }
            }
        }

        return ans;
    }
};