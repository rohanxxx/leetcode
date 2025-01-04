class Solution {
public:
    string minWindow(string s, string t) {
     // Count the occurrences of each character in string t
        unordered_map<char, int> m;
        for (int i = 0; i < t.size(); i++) {
            m[t[i]]++;
        }
        
        int i = 0;                // Left pointer of the sliding window
        int j = 0;                // Right pointer of the sliding window
        
        int counter = t.size();   // Number of characters in t that must be present in the current window
        
        int minStart = 0;         // Start index of the minimum window
        int minLength = INT_MAX;   // Length of the minimum window
        
        while (j < s.size()) {
            // If the character in s is required for the window, decrease the counter
            if (m[s[j]] > 0) {
                counter--;
            }
            
            // Decrease the count of the character in the window
            m[s[j]]--;
            
            // Move the right pointer to expand the window
            j++;
            
            // When a valid window is found, move the left pointer to find a smaller window
            while (counter == 0) {
                // Update the minimum window information if the current window is smaller
                if (j - i < minLength) {
                    minStart = i;
                    minLength = j - i;
                }
                
                // Increase the count of the character going out of the window
                m[s[i]]++;
                
                // When a required character is present in the window, increase the counter
                if (m[s[i]] > 0) {
                    counter++;
                }
                
                // Move the left pointer to shrink the window
                i++;
            }
            
        }
        
        // Check if a valid minimum window was found
        if (minLength != INT_MAX) {
            return s.substr(minStart, minLength);
        }
        return "";
    }
};