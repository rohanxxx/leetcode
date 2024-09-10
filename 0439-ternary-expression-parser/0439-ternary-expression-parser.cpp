class Solution {
public:
// Checks if the string is a valid atomic ternary expression
    bool isValidAtomic(const string& s) {
        return (s[0] == 'T' || s[0] == 'F') && s[1] == '?' &&
               ((s[2] >= '0' && s[2] <= '9') || s[2] == 'T' || s[2] == 'F') &&
               s[3] == ':' && ((s[4] >= '0' && s[4] <= '9') || s[4] == 'T' || s[4] == 'F');
    }

    char solveAtomic(const string& s) {
        if (s[0] == 'T') {
            return s[2];  // Return the true value (after '?')
        } else {
            return s[4];  // Return the false value (after ':')
        }
    }

    string parseTernary(string expression) {
        while (expression.size() > 1) {
            int i = expression.size() - 1;
            // Find valid atomic ternary expression from the end
            while (!isValidAtomic(expression.substr(i - 4, 5))) {
                i--;
            }
            // Solve the atomic expression and reduce the overall expression
            expression = expression.substr(0, i - 4) + solveAtomic(expression.substr(i - 4, 5)) + expression.substr(i + 1);
        }
        return expression;
    }
};