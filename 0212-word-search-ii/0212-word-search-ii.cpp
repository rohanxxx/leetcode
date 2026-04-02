class Solution {
public:
    class TrieNode {
    private:
        vector<TrieNode*> links;
        bool isWord;

    public:
        TrieNode() {
            this->links.resize(26, nullptr);
            this->isWord = false;
        }

        bool containsKey(char c) {
            if (this->links[c - 'a'] == NULL) {
                return false;
            }
            return true;
        }

        void put(char c) {
            this->links[c - 'a'] = new TrieNode();
        }

        TrieNode* getNextNode(char c) {
            return this->links[c - 'a'];
        }

        void setWord() {
            this->isWord = true;
        }

        bool getWord() {
            return this->isWord;
        }

        void addWord(string& word) {
            TrieNode* node = this;
            for (char c : word) {
                if (node->containsKey(c) == false) {
                    node->put(c);
                }
                node = node->getNextNode(c);
            }
            node->setWord();
        }
    };

    void dfs(int r, int c, TrieNode* node, string& word,
             vector<pair<int, int>>& dir, unordered_set<string>& st,
             vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        char ch = board[r][c];
        node = node->getNextNode(ch);

        if (node == NULL) {
            return;
        }

        word.push_back(ch);

        if (node->getWord() == true) {
            st.insert(word);
        }

        board[r][c] = '#';

        for (auto d : dir) {
            int adjr = d.first + r;
            int adjc = d.second + c;

            if (adjr >= 0 && adjc >= 0 && adjr < n && adjc < m &&
                board[adjr][adjc] != '#') {
                if (node->getNextNode(board[adjr][adjc]) != NULL) {
                    dfs(adjr, adjc, node, word, dir, st, board);
                }
            }
        }

        board[r][c] = ch;
        word.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* trie = new TrieNode();

        for (auto word : words) {
            trie->addWord(word);
        }

        unordered_set<string> st;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

        int n = board.size();
        int m = board[0].size();

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (trie->getNextNode(board[r][c]) != NULL) {
                    string word = "";
                    dfs(r, c, trie, word, dir, st, board);
                }
            }
        }

        return vector<string>(st.begin(), st.end());
    }
};