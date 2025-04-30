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
        //O(logN)
        set.erase(beginWord);
        while(!q.empty()){
            count++;
            int size = q.size();
            for(int i = 0; i < size; i++){
                string node = q.front(); q.pop();
                if(node == endWord) return count;
                //O(k*26*logN)
                for(int i = 0; i < node.size(); i++){
                    char original = node[i];
                    //O(26)
                    for(char c = 'a'; c <= 'z'; c++){
                        node[i] = c;
                        if(set.find(node) != set.end()){
                            q.push(node);
                            //O(logN)
                            set.erase(node);
                        }
                    }
                    node[i] = original;
                }
            }
        }
        return 0;
    }
};