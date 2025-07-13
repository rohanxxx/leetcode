struct TrieNode {
    TrieNode* children[26] = {NULL};
    bool isEndOfWord = false;
};

class Trie {
private:
    TrieNode* root;
public:
    Trie (){root = new TrieNode();}
    void insert(string& word){
        TrieNode* node = root;
        for(char& c: word){
            if(node->children[c-'a'] == NULL){
                node->children[c-'a'] = new TrieNode();
            }
            node = node->children[c-'a'];
        }
        node->isEndOfWord = true;
    }

    string getPrefix(string& word){
        TrieNode* node = root;
        string prefix = "";
        for(char& c: word){
            node = node->children[c-'a'];
            
            if(node == NULL) return "";
            
            prefix += c;
            if(node->isEndOfWord == true) return prefix;
        }
        return "";
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie* trie = new Trie();
        //insert the dict
        for(auto& word: dictionary){
            trie->insert(word);
        }

        stringstream ss(sentence);
        string word = "", ans = "";
        while(ss >> word){
            string cur = trie->getPrefix(word);
            
            if(cur == "") ans += word;
            else ans += cur;
            
            ans += " ";
        }

        ans.pop_back();

        return ans;
    }
};