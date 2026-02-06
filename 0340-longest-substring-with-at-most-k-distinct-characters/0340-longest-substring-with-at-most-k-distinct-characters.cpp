class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int strSize = s.size();
        if(strSize < k+1) return strSize;

        map <char, int> hashmap;

        int left = 0, right = 0;
        int longest_len = 0;
        while(right < strSize){
            hashmap[s[right]] = right;
            right++;
            
            if(hashmap.size() == k+1){
                int del_index = INT_MAX;
                for(pair<char,int> element: hashmap){
                    del_index = min(del_index, element.second);
                }
                hashmap.erase(s[del_index]);
                left = del_index+1;
            }

            longest_len = max(longest_len, right-left);
        }
        return longest_len;
    }
};