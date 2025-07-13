struct TrieNode {
    TrieNode* children[26] = {NULL};
    bool isEndOfWord = false;
};

class Trie {
private:
    TrieNode* root;
public:
    Trie(){root = new TrieNode();}

    void insert(string& word){
        TrieNode* node = root;
        for(char c: word){
            int index = c - 'a';
            if(node->children[index] == NULL){
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }
        node->isEndOfWord = true;
    }

    bool checkPrefix(string& word){
        TrieNode* node = root;
        for(char c: word){
            node = node->children[c-'a'];
            if(node == NULL || node->isEndOfWord == false){
                return false;
            }
        }
        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie* trie = new Trie();
        string ans = "";

        //insert all the words first
        //TC: O(N*L)
        //SC: O(N*L*26)
        for(string& word: words){
            trie->insert(word);
        }

        //check for the longest word with prefix
        //TC: O(N*L)
        for(string& word: words){
            if(trie->checkPrefix(word) == true){
                if(word.size() > ans.size() || (word.size() == ans.size() && word < ans)){
                    ans = word;
                }
            }
        }

        return ans;
    }
};