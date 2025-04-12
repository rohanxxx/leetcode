class Solution {
public:
    string removeKdigits(string num, int k) {
        deque<char> stack;

        for (char digit : num) {
            while (!stack.empty() && k > 0 && stack.back() > digit) {
                stack.pop_back();
                k--;
            }
            stack.push_back(digit);
        }

        // Remove remaining digits from the back if needed
        for (int i = 0; i < k; ++i) {
            stack.pop_back();
        }

        // Build result while skipping leading zeros
        string result;
        bool leadingZero = true;
        for (char digit : stack) {
            if (leadingZero && digit == '0') continue;
            leadingZero = false;
            result += digit;
        }

        if (result.empty()) {
            return "0";
        } else {
            return result;
        }
    }
};