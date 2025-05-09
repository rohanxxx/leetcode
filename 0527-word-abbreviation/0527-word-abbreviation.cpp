/*
        array of distinct words
        abbreviation primary rule first character middle character counts plus last character
        -> if more than one word shares the same abbreviation then increase the prefix
        -> if in the process of increasing prefix if any word is not shorter than the original word then keep it original

        Input: words = ["like","god","internal","me","internet","interval","intension","face","intrusion"]
        input: words = [me, god, face, like, internet, internal, interval, intension, instrusion]
        
        Output: ["l2e","god","internal","me","i6t","interval","inte4n","f2e","intr4n"]

        god
        internal
        me
        interval
        
        if(word.size() <= 3) then keep it same
*/
class Solution {
public:
    vector<string> wordsAbbreviation(vector<string>& words) {
        int N = words.size();
        vector<string> ans(N);
        vector<int> prefix(N, 0);

        // Step 1: Generate initial abbreviations
        for (int i = 0; i < N; ++i)
            ans[i] = abbrev(words[i], 0);

        // Step 2: Resolve conflicts by increasing prefix length
        for (int i = 0; i < N; ++i) {
            while (true) {
                //stores the index of duplicates
                unordered_set<int> dupes;
                for (int j = i + 1; j < N; ++j) {
                    if (ans[i] == ans[j])
                        dupes.insert(j);
                }

                if (dupes.empty()) break;

                dupes.insert(i);
                for (int k : dupes) {
                    ++prefix[k];
                    ans[k] = abbrev(words[k], prefix[k]);
                }
            }
        }

        return ans;
    }

private:
    string abbrev(const string& word, int i) {
        int N = word.length();
        if (N - i <= 3) return word;
        return word.substr(0, i + 1) + to_string(N - i - 2) + word.back();
    }
};