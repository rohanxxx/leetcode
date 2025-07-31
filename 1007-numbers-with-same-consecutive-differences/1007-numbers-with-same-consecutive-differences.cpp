class Solution {
public:
    unordered_set<int> bfs(int n, int k) {
        queue<int> q;
        for (int i = 1; i <= 9; i++) q.push(i);  // Start from 1 to 9

        unordered_set<int> set;
        while (!q.empty()) {
            int curNum = q.front(); q.pop();

            //ans condition here 
            if (to_string(curNum).size() == n) {
                set.insert(curNum);
                continue;
            }

            int prevDigit = curNum % 10;

            if (prevDigit + k < 10) {
                int newNum = curNum * 10 + (prevDigit + k);
                q.push(newNum);
            }

            // avoid duplicate when k == 0
            if (prevDigit - k >= 0) {
                int newNum = curNum * 10 + (prevDigit - k);
                q.push(newNum);
            }
        }

        return set;
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        unordered_set<int> set = bfs(n, k);
        return vector<int> (set.begin(), set.end());
    }
};