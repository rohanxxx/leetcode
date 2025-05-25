class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_map<char, char> next = {
            {'0', '1'},
            {'1', '2'},
            {'2', '3'},
            {'3', '4'},
            {'4', '5'},
            {'5', '6'},
            {'6', '7'},
            {'7', '8'},
            {'8', '9'},
            {'9', '0'}
        };
        unordered_map<char, char> prev = {
            {'0', '9'},
            {'1', '0'},
            {'2', '1'},
            {'3', '2'},
            {'4', '3'},
            {'5', '4'},
            {'6', '5'},
            {'7', '6'},
            {'8', '7'},
            {'9', '8'}
        };

        unordered_set<string> visited(deadends.begin(), deadends.end());
        queue<pair<int, string>> q;
        q.push({0, "0000"});
        if(visited.find("0000") == visited.end()){
            visited.insert("0000");
        }
        else{
            return -1;
        }
    
        while(!q.empty()){
            int curTurn = q.front().first;
            string curComb = q.front().second;
            
            q.pop();
            
            if(curComb == target){
                return curTurn;
            }

            for(int i = 0; i < 4; i++){
                char c = curComb[i];
                string nextComb = curComb;
                string prevComb = curComb;
                nextComb[i] = next[c];
                prevComb[i] = prev[c];
                if(visited.find(nextComb) == visited.end()){
                    q.push({curTurn+1, nextComb});
                    visited.insert(nextComb);
                }
                if(visited.find(prevComb) == visited.end()){
                    q.push({curTurn+1, prevComb});
                    visited.insert(prevComb);
                }
            }
        }

        return -1;
    }
};