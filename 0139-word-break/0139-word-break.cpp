class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        
        queue<int> q;
        
        vector<bool> seen(s.length(), false);

        q.push(0);
        
        while(!q.empty()){
            int start = q.front();
            q.pop();
            
            if(start == s.length()) return true;
            
            for(int end = start+1; end <= s.length(); end++){
                if(seen[end]) continue;
                if(words.find(s.substr(start, end-start)) != words.end()){
                    q.push(end);
                    seen[end] = true;
                }
            }
        }
        
        return false;
    }
};