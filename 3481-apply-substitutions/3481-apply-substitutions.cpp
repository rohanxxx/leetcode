class Solution {
public:
    string applySubstitutions(vector<vector<string>>& replacements, string text) {
        vector<vector<int>> graph(26);

        vector<string> map(26);
        vector<int> indegree(26, 0);
        vector<int> exists(26, 0);

        for (auto it : replacements) {
            string key = it[0];
            int u = key[0] - 'A';
            exists[u] = 1;

            vector<int> seen(26, 0);

            for (int i = 0; i + 2 < (int)it[1].size(); i++) {
                if (it[1][i] == '%' &&
                    it[1][i + 2] == '%' &&
                    it[1][i + 1] >= 'A' && it[1][i + 1] <= 'Z') {

                    int v = it[1][i + 1] - 'A';
                    if (!seen[v]) {
                        seen[v] = 1;
                        indegree[u]++;
                        graph[v].push_back(u);
                    }
                }
            }
            map[u] = it[1];
        }

        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (exists[i] && indegree[i] == 0) q.push(i);
        }

        // now build the proper map
        while (!q.empty()) {
            int key = q.front(); q.pop();
            string curVal = map[key];
            string updatedVal = "";

            int i = 0;
            while (i < (int)curVal.size()) {
                if (curVal[i] == '%' &&
                    i + 2 < (int)curVal.size() &&
                    curVal[i + 2] == '%' &&
                    curVal[i + 1] >= 'A' && curVal[i + 1] <= 'Z') {

                    int adjKey = curVal[i + 1] - 'A';
                    updatedVal += map[adjKey];
                    i += 3;
                    continue;
                }
                updatedVal += curVal[i];
                i++;
            }

            map[key] = updatedVal;

            for (auto adjn : graph[key]) {
                if (--indegree[adjn] == 0) {
                    q.push(adjn);
                }
            }
        }

        int i = 0;
        int n = text.size();
        string updatedVal = "";
        while (i < n) {
            if (text[i] == '%' &&
                i + 2 < n &&
                text[i + 2] == '%' &&
                text[i + 1] >= 'A' && text[i + 1] <= 'Z') {

                int adjKey = text[i + 1] - 'A';
                updatedVal += map[adjKey];
                i += 3;
                continue;
            }
            updatedVal += text[i];
            i++;
        }

        return updatedVal;
    }
};