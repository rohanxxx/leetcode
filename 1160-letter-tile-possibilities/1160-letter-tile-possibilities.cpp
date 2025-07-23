class Solution {
public:
    int count = 0;
    void backtrack(string cur, string& tiles, unordered_set<int>& visitedIndex, unordered_set<string>& visitedStrings){
        int n = tiles.size();
        
        if(cur.size() >= n) return;

        for(int i = 0; i < n; i++){
            if(visitedIndex.find(i) == visitedIndex.end()){
                visitedIndex.insert(i);
                cur += tiles[i];
                //cur string not found
                if(visitedStrings.find(cur) == visitedStrings.end()){
                    count++;
                    visitedStrings.insert(cur);
                }
                backtrack(cur, tiles, visitedIndex, visitedStrings);
                cur.pop_back();
                visitedIndex.erase(i);
            }
        }
    }
    int numTilePossibilities(string tiles) {
        unordered_set<int> visitedIndex;
        unordered_set<string> visitedStrings;

        backtrack("", tiles, visitedIndex, visitedStrings);

        return count;
    }
};