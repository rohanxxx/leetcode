class Solution {
public:
    struct TrieNode{
        TrieNode* children[26] = {NULL};
        bool isEndOfWord = false;
    };

    class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root = new TrieNode();
        }

        void insert(string& word){
            TrieNode* node = root;
            for(auto& c: word){
                if(node->children[c-'a'] == NULL){
                    node->children[c-'a'] = new TrieNode();
                }
                node = node->children[c-'a'];
            }
            node->isEndOfWord = true;
        }

        vector<vector<int>> getRange(int& index, string& word) {
            TrieNode* node = root;
            
            int n = word.size();

            vector<vector<int>> pairs;

            //TC: O(N)
            for (int i = index; i < n; i++) {
                if (node->children[word[i] - 'a'] == NULL) {
                    return pairs;
                }
                node = node->children[word[i] - 'a'];
                if (node->isEndOfWord == true) {
                    pairs.push_back({index, i});
                }
            }

            return pairs;
        }
    };
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
        Trie* trie = new Trie();
        for(auto& word: words){
            trie->insert(word);
        }

        vector<vector<int>> ans;

        int n = text.size();
        //TC: O(N*N*M)
        for(int i = 0; i < n; i++){
            vector<vector<int>> pairs = trie->getRange(i, text);
            for(auto& pair: pairs){
                ans.push_back(pair);
            }
        }

        return ans;
    }
};