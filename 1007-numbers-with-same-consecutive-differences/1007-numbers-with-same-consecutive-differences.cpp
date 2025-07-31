class Solution {
public:
    vector<int> bfs(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= 9; i++) q.push(i);  // Start from 1 to 9

        vector<int> ans;
        while (!q.empty()) {
            int curNum = q.front(); q.pop();

            if (to_string(curNum).size() == n) {
                ans.push_back(curNum);
                continue;
            }

            int prevDigit = curNum % 10;

            if (prevDigit + k < 10) {
                int newNum = curNum * 10 + (prevDigit + k);
                q.push(newNum);
            }

            // avoid duplicate when k == 0
            if (k != 0 && prevDigit - k >= 0) {
                int newNum = curNum * 10 + (prevDigit - k);
                q.push(newNum);
            }
        }

        return ans;
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        return bfs(n, k);
    }
};