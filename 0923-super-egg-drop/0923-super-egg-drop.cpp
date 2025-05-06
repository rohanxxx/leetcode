class Solution {
public:
    unordered_map<int, int> memo;

    int dp(int K, int N) {
        int key = N * 100 + K;
        if (memo.find(key) == memo.end()) {
            int ans;
            if (N == 0) {
                ans = 0;
            } else if (K == 1) {
                ans = N;
            } else {
                int lo = 1, hi = N;
                while (lo + 1 < hi) {
                    int x = (lo + hi) / 2;
                    int t1 = dp(K - 1, x - 1);
                    int t2 = dp(K, N - x);
                    if (t1 < t2) {
                        lo = x;
                    } else if (t1 > t2) {
                        hi = x;
                    } else {
                        lo = hi = x;
                    }
                }

                ans = 1 + min(
                    max(dp(K - 1, lo - 1), dp(K, N - lo)),
                    max(dp(K - 1, hi - 1), dp(K, N - hi))
                );
            }
            memo[key] = ans;
        }
        return memo[key];
    }

    int superEggDrop(int k, int n) {
        return dp(k, n);
    }
};