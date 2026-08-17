/*
    -> two words do not share the same letters in common
    -> max of len(word[i])*len(word[j])

    Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
    Output: 16
*/
class Solution {
public:
    int maxProduct(vector<string>& words) {
    int n = words.size();
    vector<vector<int>> map(n, vector<int>(26, 0));

    for(int i = 0; i < n; i++){
        for(auto c: words[i]){
            map[i][c-'a']++;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            bool shareChar = false;
            for(int k = 0; k < 26; k++){
                if(map[i][k] > 0 && map[j][k] > 0){
                    shareChar = true;
                    break;
                }
            }
            if(!shareChar){
                ans = max(ans, (int)words[i].size() * (int)words[j].size());
            }
        }
    }

    return ans;
}
// TC: O(n^2 * 26) = O(n^2), SC: O(n * 26) = O(n)
};