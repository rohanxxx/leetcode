class Solution {
public:
    int numSquares(int n) {
        // Precompute all perfect squares ≤ n
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            squares.push_back(i * i);
        }

        queue<int> q;
        unordered_set<int> visited;

        q.push(n);
        visited.insert(n);

        int level = 0;

        while (!q.empty()) {
            int size = q.size();
            level++;

            while (size--) {
                int remainder = q.front();
                q.pop();

                for (int square : squares) {
                    if (remainder == square) {
                        return level;
                    }

                    if (remainder < square) {
                        break;
                    }

                    int next = remainder - square;

                    if (!visited.count(next)) {
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }

        return level;
    }
};