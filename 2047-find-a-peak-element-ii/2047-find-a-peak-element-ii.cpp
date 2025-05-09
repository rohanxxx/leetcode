class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        vector<int> v;

        for (int i = 0; i < row; i++) {
            int low = 0;
            int high = col - 1;
            while (low <= high) {
                int mid = (low + high) >> 1;

                int u, l, d, r;

                // up
                if (i > 0) {
                    u = mat[i - 1][mid];
                } else {
                    u = -1;
                }

                // left
                if (mid > 0) {
                    l = mat[i][mid - 1];
                } else {
                    l = -1;
                }

                // down
                if (i < row - 1) {
                    d = mat[i + 1][mid];
                } else {
                    d = -1;
                }

                // right
                if (mid < col - 1) {
                    r = mat[i][mid + 1];
                } else {
                    r = -1;
                }

                int m1 = max(u, d);
                int m2 = max(l, r);
                int l1 = max(l, mat[i][0]);
                int l2 = max(r, mat[i][col - 1]);

                if (mat[i][mid] >= max(m1, m2)) {
                    v.push_back(i);
                    v.push_back(mid);
                    return v;
                } else if (l1 > l2) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
        }
        return v;
    }
};