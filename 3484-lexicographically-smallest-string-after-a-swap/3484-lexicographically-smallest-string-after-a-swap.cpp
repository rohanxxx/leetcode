class Solution {
public:
    string getSmallestString(string s) {
        for(int i = 1; i < s.length(); i++)
        {
            int curr = s[i] - '0';
            int prev = s[i - 1] - '0';
            if(curr % 2 == prev % 2)
            {
                if(curr < prev)
                {
                    swap(s[i], s[i-1]);
                    break;
                }
            }
        }
        return s;
    }
};