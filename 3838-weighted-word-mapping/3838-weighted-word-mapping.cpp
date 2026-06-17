class Solution {
public:
    /*
          z y x  w  v u t s r  q p o n m l k  j i h g f e d c b a
         [5,3,12,14,1,2,3,2,10,6,6,9,7,8,7,10,8,9,6,9,9,8,3,7,7,2]
    */
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(auto w: words){
            int word_sum = 0;
            for(auto c: w){
                word_sum += weights[c-'a'];
            }
            ans.push_back('a'+(25-(word_sum%26)));
        }
        return ans;
    }
};