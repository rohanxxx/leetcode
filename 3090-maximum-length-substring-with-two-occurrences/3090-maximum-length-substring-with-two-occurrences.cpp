class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.length();

        int left = 0, ans = 0;
        unordered_map<int, int> hashmap;
        for(int right = 0; right < n; right++){
            hashmap[s[right]]++;
            while(hashmap[s[right]] > 2){
                hashmap[s[left]]--;
                left++;
            }

            ans = max(ans, right-left+1);
        }

        return ans;
    }
};