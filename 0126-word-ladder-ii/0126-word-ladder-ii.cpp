class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string curr, string beginWord, vector<string>& node){
        if(curr == beginWord){
            ans.push_back(node);
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
            int n = q.size();
            bool found = false;

            //level order traversal
            for(int i = 0; i < n; i++){
                string curr = q.front(); q.pop();

                if(curr == endWord){
                    found = true;
                }

                string temp = curr;

                for(int j = 0; j < temp.size() && !found; j++){
                    char o = temp[j];

                    for(char c = 'a'; c <= 'z'; c++){
                        temp[j] = c;

                        if(wordSet.find(temp) != wordSet.end()){
                            // first time visiting
                            if(levelCount.find(temp) == levelCount.end()){
                                levelCount[temp] = levelCount[curr] + 1;
                                q.push(temp);
                                parent[temp].push_back(curr);
                            }
                            // same level → multiple parents
                            else if(levelCount[temp] == levelCount[curr] + 1){
                                parent[temp].push_back(curr);
                            }
                        }
                    }

                    temp[j] = o;
                }
            }

            if(found == true) {
                break;
            }
        }

        //if there is no answer then return empty vector
        if(levelCount.find(endWord) == levelCount.end()) {
            return {};
        }

        vector<string> node = {endWord};
        dfs(endWord, beginWord, node);

        for(auto& it: ans){
            reverse(it.begin(), it.end());
        }

        return ans;
    }
};