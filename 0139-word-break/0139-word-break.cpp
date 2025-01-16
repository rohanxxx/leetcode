class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        
        queue<int> q; q.push(0);
        vector<bool> seen(n, false);
        unordered_set<string> words(wordDict.begin(), wordDict.end());

        while(!q.empty()){
            int start = q.front(); q.pop();
            if(start == n) return true;

            for(int end = start+1; end <= n; end++){
                if(seen[end]) continue;
                if(words.find(s.substr(start, end-start)) != words.end()){
                    seen[end] = true;
                    q.push(end);
                }
            }
        }

        return false;
    }
};