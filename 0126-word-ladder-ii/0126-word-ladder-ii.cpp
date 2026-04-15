class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string curr, string beginWord, vector<string>& node){
        if(curr == beginWord){
            reverse(node.begin(), node.end());
            ans.push_back(node);
            reverse(node.begin(), node.end());
            return;
        }

        for(auto &p : parent[curr]){
            node.push_back(p);
            dfs(p, beginWord, node);
            node.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        queue<string> q;
        q.push(beginWord);

        unordered_map<string, int> levelCount;
        levelCount[beginWord] = 0;

        while(!q.empty()){
            string curr = q.front(); q.pop();
            int currLevel = levelCount[curr];

            string temp = curr;

            for(int i = 0; i < temp.size(); i++){
                char o = temp[i];

                for(char c = 'a'; c <= 'z'; c++){
                    temp[i] = c;

                    if(wordSet.find(temp) != wordSet.end()){
                        // first time visiting
                        if(levelCount.find(temp) == levelCount.end()){
                            levelCount[temp] = currLevel + 1;
                            q.push(temp);
                            parent[temp].push_back(curr);
                        }
                        // same level → multiple parents
                        else if(levelCount[temp] == currLevel + 1){
                            parent[temp].push_back(curr);
                        }
                    }
                }

                temp[i] = o;
            }
        }

        if(levelCount.find(endWord) == levelCount.end()) return {};

        vector<string> node;
        node.push_back(endWord);
        dfs(endWord, beginWord, node);

        return ans;
    }
};