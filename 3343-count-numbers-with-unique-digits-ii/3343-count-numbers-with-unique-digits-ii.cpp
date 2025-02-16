class Solution {
public:
    int numberCount(int a, int b) {
        int count = 0;
        for(int i = a; i < b+1; i++){
            string current = to_string(i);
            unordered_set<char> set(current.begin(), current.end());
            if(current.length() == set.size()){
                count++;
            }
        }

        return count;
    }
};