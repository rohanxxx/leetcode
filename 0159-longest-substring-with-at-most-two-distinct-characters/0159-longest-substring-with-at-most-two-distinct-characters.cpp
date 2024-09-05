class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int strSize = s.size();
        if(strSize < 3) return strSize;

        map <char, int> hashmap;

        int left = 0, right = 0;
        int longest_len = 2;
        while(right<strSize){
            hashmap[s[right]] = right;
            right++;
            
            if(hashmap.size() == 3){
                int del_index = INT_MAX;
                for(pair<char,int> element: hashmap){
                    del_index = min(del_index, element.second);
                }
                hashmap.erase(s[del_index]);
                left = del_index+1;
            }

            longest_len = max(longest_len, right-left);
            // cout << "s[right]: " << s[right] << endl;
        }
        return longest_len;
    }
};