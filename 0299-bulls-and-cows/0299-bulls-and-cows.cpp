/*
    Input: secret = "1807", guess = "7810"
    Output: "1A3B"

    secret = "1807", guess = "7810"
    1A3B

    Input: secret = "1123", guess = "0111"
    Output: "1A1B"

    secret = "1123", guess = "0111"
    1A1B

    secretFreq
    1 -> 2
    2 -> 1
    3 -> 1

    guessFreq
    0 -> 1
    1 -> 3

    int bullCount = 0;
    int cowCount = 0;
    for(i->guess.size()){
        if(g[i] == s[i]){
            sfreq[i]--;
            bullCount++;
        }
        else{
            if(sfreq[g[i]] > 0){
                cowCount++;
                sfreq[g[i]]--;
            }
        }
    }
*/
class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char, int> h;
        for (char s : secret) {
            h[s]++;
        }

        int bulls = 0, cows = 0;
        int n = guess.length();
        for (int idx = 0; idx < n; ++idx) {
            char ch = guess[idx];
            if (h.count(ch)) {
                if (ch == secret[idx]) {
                    bulls++;
                    if (h[ch] <= 0)
                        cows--;
                } else {
                    if (h[ch] > 0)
                        cows++;
                }
                h[ch]--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};