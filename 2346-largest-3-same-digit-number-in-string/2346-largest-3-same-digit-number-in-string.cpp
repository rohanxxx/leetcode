class Solution {
public:
    string largestGoodInteger(string num) {
        // Assign 'maxDigit' to the NUL character (smallest ASCII value character)
        char maxDigit = '\0';

        // Iterate on characters of the num string.
        for (int index = 0; index <= num.size() - 3; ++index) {
            // If 3 consecutive characters are the same,
            // store the character in 'maxDigit' if bigger than what it already stores.
            if (num[index] == num[index + 1] && num[index] == num[index + 2]) {
                if (num[index] > maxDigit) {
                    maxDigit = num[index];
                }
            }
        }

        // Use regular if-else instead of ternary operator
        if (maxDigit == '\0') {
            return "";
        } else {
            return string(3, maxDigit);
        }
    }
};