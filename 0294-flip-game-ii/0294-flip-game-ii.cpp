class Solution {
public:
    unordered_map<string, bool> memo;

    bool dfs(int& n, string& state){
        // memo check
        if(memo.count(state)) return memo[state];

        for(int i = 0; i < n; i++){
            if(i + 1 < n && state[i] == '+' && state[i+1] == '+'){
                //hasMove = true;

                // make move
                state[i] = '-';
                state[i+1] = '-';

                // opponent turn
                bool nextPlayer = dfs(n, state);

                // backtrack
                state[i] = '+';
                state[i+1] = '+';

                // if opponent loses → win
                if(nextPlayer == false){
                    return memo[state] = true;
                }
            }
        }

        // no moves → lose
        return memo[state] = false;
    }

    bool canWin(string currentState) {
        int n = currentState.length();
        return dfs(n, currentState);
    }
};