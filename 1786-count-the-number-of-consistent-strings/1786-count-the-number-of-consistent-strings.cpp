class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_map<char, int> map; //SC: O(26)
        //TC: O(N)
        for(char c: allowed){
            map[c] = 1;
        }
        int count = 0;
        //TC: O(N*M)
        for(auto word: words){
            bool notIn = false;
            for(char w: word){
                if(map[w] == 0){
                    notIn = true;
                    break;
                }
            }
            if(notIn == false) count++;
        }
        return count;
    }
};