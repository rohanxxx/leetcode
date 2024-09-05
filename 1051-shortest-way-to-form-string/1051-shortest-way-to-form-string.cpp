class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_map<char, bool> sourceChars;
        for(char c: source) sourceChars[c] = true;
        for(char c: target){
            if(sourceChars[c] == false) return -1;
        }

        int n = source.length();
        int sourceIterator = 0; int count = 0;

        for(char c: target){
            if(sourceIterator == 0) count++;
            while(source[sourceIterator] != c){
                sourceIterator = (sourceIterator+1)%n;
                if(sourceIterator == 0) count++;
            }
            sourceIterator = (sourceIterator+1)%n;
        }
        
        return count;
    }
};