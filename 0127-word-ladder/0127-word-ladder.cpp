class Solution {
public:
    //TC: O(N+N*K*log(N))
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //TC: O(N)
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> q; q.push(beginWord);
        
        int count = 0;
        while(!q.empty()){
            count++;
            int size = q.size();
            //TC: O(26*N*K*Log(N))
            for(int i = 0; i < size; i++){
                string word = q.front(); q.pop();
                if(word == endWord){
                    return count;
                }
                //TC: O(K)
                for(int j = 0; j < word.size(); j++){
                    char curChar = word[j];
                    for(char c = 'a'; c <= 'z'; c++){
                        word[j] = c;
                        //if found
                        //TC: Log(N)
                        if(dict.find(word) != dict.end()){
                            dict.erase(word);
                            q.push(word);
                        }
                    }
                    word[j] = curChar;
                }
            }
        }
        
        return 0;
    }
};