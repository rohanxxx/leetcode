/*
      0 1 2 3
    0 . Q . .
    1 . . . Q
    2 Q . . .
    3 . . Q .
    
    rowVec formula => r
    colVec formula => c
    antiDag formula => r+c
    dag formula => abs(n-1-r)+c
*/
class Solution {
public:
    bool check(int r, int c,
               unordered_set<int>& rowVec,
               unordered_set<int>& colVec,
               unordered_set<int>& dagVec,
               unordered_set<int>& antiDagVec,
               int n) {

        if ((rowVec.find(r) != rowVec.end()) ||
            (colVec.find(c) != colVec.end()) ||
            (antiDagVec.find(r + c) != antiDagVec.end()) ||
            (dagVec.find((n - 1 - r) + c) != dagVec.end())) {
            return true;
        }

        return false;
    }

    void dfs(int r, int& n,
             unordered_set<int>& rowVec,
             unordered_set<int>& colVec,
             unordered_set<int>& dagVec,
             unordered_set<int>& antiDagVec,
             vector<string>& currState,
             vector<vector<string>>& ans) {

        if (r == n) {
            ans.push_back(currState);
            return;
        }

        for (int c = 0; c < n; c++) {
            if (check(r, c, rowVec, colVec, dagVec, antiDagVec, n) == true) {
                continue;
            }

            currState[r][c] = 'Q';
            rowVec.insert(0);
            colVec.insert(c);
            dagVec.insert((n - 1 - r) + c);
            antiDagVec.insert(r + c);

            dfs(r + 1, n, rowVec, colVec, dagVec, antiDagVec, currState, ans);

            currState[r][c] = '.';
            rowVec.erase(0);
            colVec.erase(c);
            dagVec.erase((n - 1 - r) + c);
            antiDagVec.erase(r + c);
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        string dummy = "";
        for (int i = 0; i < n; i++) {
            dummy += ".";
        }

        vector<string> currState(n, dummy);

        unordered_set<int> rowVec, colVec;
        unordered_set<int> dagVec, antiDagVec;

        int r = 0;

        for (int c = 0; c < n; c++) {
            if (check(r, c, rowVec, colVec, dagVec, antiDagVec, n) == true) {
                continue;
            }

            currState[r][c] = 'Q';
            rowVec.insert(0);
            colVec.insert(c);
            dagVec.insert((n - 1 - r) + c);
            antiDagVec.insert(r + c);

            dfs(r + 1, n, rowVec, colVec, dagVec, antiDagVec, currState, ans);

            currState[r][c] = '.';
            rowVec.erase(0);
            colVec.erase(c);
            dagVec.erase((n - 1 - r) + c);
            antiDagVec.erase(r + c);
        }

        return ans;
    }
};