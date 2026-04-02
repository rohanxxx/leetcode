class TrieNode {
private:
    vector<TrieNode*> links;
    bool flag;
public:
    TrieNode(){
        this->links.resize(26);
        this->flag = false;
    }
    
    bool containsKey(char c){
        if(this->links[c-'a'] == NULL){
            return false;
        }
        return true;
    }

    void put(char c){
        this->links[c-'a'] = new TrieNode();
    }

    TrieNode* getNext(char c){
        return this->links[c-'a'];
    }
    void setEnd(){
        this->flag = true;
    }
    bool getEnd(){
        return this->flag;
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        int n = word.size();
        TrieNode* node = this->root;
        for(int i = 0; i < n; i++){
            if(!node->containsKey(word[i])){
                node->put(word[i]);
            }
            node = node->getNext(word[i]);
        }
        //at the end we have to mark the node true
        node->setEnd();
    }
    
    bool search(string word) {
        int n = word.size();
        TrieNode* node = this->root;
        for(int i = 0; i < n; i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->getNext(word[i]);
        }
        return node->getEnd();
    }
    
    bool startsWith(string prefix) {
        int n = prefix.size();
        TrieNode* node = this->root;
        for(int i = 0; i < n; i++){
            if(!node->containsKey(prefix[i])){
                return false;
            }
            node = node->getNext(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */