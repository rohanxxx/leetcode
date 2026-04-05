/*
    Input: s = "ababcbacadefegdehijhklij"
    Output: [9,7,8]

    0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23
    a b a b c b a c a d e  f  e  g  d  e  h  i  j  h  k  l  i  j"

    cur-> a b c d e f g h i j k l m n o p q r s t u v w x y z
          4 3 2 2 3 1 1 2 2 2 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0
          4 3 2 2 2 1 1 1

          if(map2[s[i]] > 0 && map2[s[i]] != map1[s[i]]){
            break;
          }
*/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        //SC: O(52) -> O(1)
        vector<int> sMap(26, 0), map(26, 0);
        for(auto& c: s) sMap[c-'a']++;

        vector<int> ans;
        int n = s.length(), prev = -1;
        //TC: O(N*26)
        for(int i = 0; i < n; i++){
            char c = s[i];
            map[c-'a']++;
            
            bool check = true;
            //TC: O(26)
            for(int i = 0; i < 26; i++){
                if(map[i] > 0 && map[i] != sMap[i]){
                    check = false;
                    break;
                }
            }

            if(check == true){
                ans.push_back(i-prev);
                prev = i;
            }
        }

        return ans;
    }
};