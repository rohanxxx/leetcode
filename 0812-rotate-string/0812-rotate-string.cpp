class Solution {
public:
     bool rotateString(std::string s, std::string goal) {
        if(s.length() != goal.length()) return false;
        
        string doubleString = s + s;  
        
        if (doubleString.find(goal) != std::string::npos) return true;
        
        return false;
    }
};