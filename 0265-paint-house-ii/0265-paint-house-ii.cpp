class Solution {
private:
    int n;  // Number of houses
    int k;  // Number of colors
    vector<vector<int>> costs;
    unordered_map<string, int> memo;

public:
    int minCostII(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;

        this->k = costs[0].size();
        this->n = costs.size();
        this->costs = costs;
        int minCost = INT_MAX;

        // Try painting the first house with each color and take the minimum cost.
        for (int color = 0; color < k; color++) {
            minCost = min(minCost, memoSolve(0, color));
        }
        return minCost;
    }

private:
    int memoSolve(int houseNumber, int color) {
        // Base case: If we're at the last house, return the cost of painting it with the current color.
        if (houseNumber == n - 1) {
            return costs[houseNumber][color];
        }

        // Check if the subproblem is already solved (memoization).
        string key = getKey(houseNumber, color);
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // Recursive case: Try all colors for the next house except the current one.
        int minRemainingCost = INT_MAX;
        for (int nextColor = 0; nextColor < k; nextColor++) {
            if (color == nextColor) continue;  // Skip the same color
            int currentRemainingCost = memoSolve(houseNumber + 1, nextColor);
            minRemainingCost = min(currentRemainingCost, minRemainingCost);
        }

        // Add the cost of painting the current house with the current color.
        int totalCost = costs[houseNumber][color] + minRemainingCost;

        // Memoize the result.
        memo[key] = totalCost;
        return totalCost;
    }

    // Create a unique key based on house number and color for memoization.
    string getKey(int houseNumber, int color) {
        return to_string(houseNumber) + " " + to_string(color);
    }
};