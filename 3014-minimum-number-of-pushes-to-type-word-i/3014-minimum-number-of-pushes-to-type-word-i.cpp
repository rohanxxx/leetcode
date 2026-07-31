class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int count = i / 8 + 1;
            ans += count;
            cout << "i: " << i << " count: " << count << endl;
        }
        return ans;
    }
};