class Solution {
public:
    int shortestPathWithHops(int n, vector<vector<int>>& edges, int s, int d, int k) {
        vector<vector<pair<int, int>>> con(n);
        for (const auto & e : edges) {
            con[e[0]].push_back({e[1], e[2]});
            con[e[1]].push_back({e[0], e[2]});
        }
        priority_queue<tuple<int, int, int>> q;
        q.push({0, k, s});
        vector<vector<int>> dist(n, vector<int>(k + 1, INT_MAX));
        vector<vector<bool>> mark(n, vector<bool>(k + 1));
        dist[s][k] = 0;
        while (!q.empty()) {
            const auto [t, m, x] = q.top();
            q.pop();
            if (mark[x][m]) {
                continue;
            }
            mark[x][m] = true;
            if (x == d) {
                return -t;
            }
            for (const auto& p : con[x]) {
                if (p.second - t < dist[p.first][m]) {
                    dist[p.first][m] = p.second - t;
                    q.push({-dist[p.first][m], m, p.first});
                }
                if (m && -t < dist[p.first][m - 1]) {
                    dist[p.first][m - 1] = -t;
                    q.push({-dist[p.first][m - 1], m - 1, p.first});
                }
            }
        }
        return -1;
    }
};