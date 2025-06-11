class Solution {
public:
    vector<string> generatePossibleNextMoves(string currentState) {
        //TC: O(N^2)
        int n = currentState.length();
        vector<string> ans;
        for(int i = 0; i < n-1; i++){
            if(currentState[i] == '-' || currentState[i+1] == '-') continue;
            string state = currentState;
            state[i] = '-';
            state[i+1] = '-';
            ans.push_back(state);
        }
        return ans;
    }
};