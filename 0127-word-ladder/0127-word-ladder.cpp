class Solution {
public:
/*
    beginWord<->EndWord
    beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
*/
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> set(wordList.begin(), wordList.end());
        
        int count = 0;
        queue<string> q; q.push(beginWord);
        set.erase(beginWord);
        while(!q.empty()){
            count++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                string node = q.front(); q.pop();
                if(node == endWord) return count;
                for(int i = 0; i < node.size(); i++){
                    string temp = node;
                    for(char c = 'a'; c <= 'z'; c++){
                        temp[i] = c;
                        if(set.find(temp) != set.end()){
                            q.push(temp);
                            set.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};