/*
    - All words in each array comprise of lowercase English letters and have the same length.
    - Find all words from queries that, after a maximum of two edits, equal some word from dictionary.
    - Return a list of all words from queries, that match with some word from dictionary after a maximum of two edits.
    - Return the words in the same order they appear in queries

    queries = ["word","note","ants","wood"], dictionary = ["wood","joke","moat"]

    [word -> note-> wood]

    N*M*L
*/
class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        //TC(N*M*L)
        for(string word: queries){
            //TC: O(M*L)
            for(string w: dictionary){
                int L = w.length();
                int count = 0;
                //TC: O(L)
                for(int i = 0; i < L; i++){
                    if(w[i] != word[i]){
                        count++;
                        if(count > 2){
                            break;
                        }
                    }
                }
                if(count <= 2){
                    ans.push_back(word);
                    break;
                }
            }
        }

        return ans;
    }
};