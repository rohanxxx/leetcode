class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;

        for (int n : nums) {
            count[n] += 1;

            if (count.size() <= 2) {
                continue;
            }

            unordered_map<int, int> new_count;
            for (auto& [n, c] : count) {
                if (c > 1) {
                    new_count[n] = c - 1;
                }
            }
            count = new_count;
        }

        vector<int> res;
        for (auto& [n, c] : count) {
            if (std::count(nums.begin(), nums.end(), n) > (int)nums.size() / 3) {
                res.push_back(n);
            }
        }
        return res;
    }
};