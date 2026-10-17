/*
    list of strings words and a string pattern
    return a list of words[i] that match pattern. You can return the answer in any order

    a word matches the pattern if there exists a permutation of letters p so that after replacing every letter maps to another letter and no two letter maps to the same letter


    Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
    Output: ["mee","aqq"]

    use two pointer technique
    words[i] and patter[i] while iterating those we will map 

    abc -> abb
    d   -> a
    e   -> b
    q   -> b

    cond1 -> if(map1[words[i][j]] not mapped and map2[pattern[j]] is not also mapped){
        then we map
    }

    cond2 -> if(map1[words[i][j]] is mapped and map2[pattern[j]] is mapped){
        cond3 -> if(!map1[wirds[i][j]] == pattern[j] && map2[pattern[j]] == words[i][j]){
            break;
        }
    }
    else { 
        break
    }
*/
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        //SC: O(2*26) -> O(1)
        vector<int> word_map(26), pattern_map(26);

        vector<string> ans;

        int n = pattern.size();
        //TC: O(2*26*M*N)
        for(auto word: words){
            bool mapped = true;

            //reset the maps before each iterations
            fill(word_map.begin(), word_map.end(), -1);
            fill(pattern_map.begin(), pattern_map.end(), -1);
            //O(N)
            for(int i = 0; i < n; i++){
                int w_i = word[i]-'a';
                int p_i = pattern[i]-'a';
                //if none of it mapped at all
                if(word_map[w_i] == -1 && pattern_map[p_i] == -1){
                    word_map[w_i] = pattern[i]-'a';
                    pattern_map[p_i] = word[i]-'a';
                    continue;
                }
                //both of them are mapped
                if(word_map[w_i] > -1 && pattern_map[p_i] > -1){
                    //now both of them are mapped check if they map each other
                    if(!(word_map[w_i] == pattern[i]-'a' && pattern_map[p_i] == word[i]-'a')){
                        mapped = false;
                        break;
                    }
                }
                else{
                    mapped = false;
                    break;
                }
            }
            if(mapped == true){
                ans.push_back(word);
            }
        }

        return ans;
    }
};