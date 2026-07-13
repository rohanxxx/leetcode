class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        int n = s.size(), left = 0, right = 0;
        
        vector<int> ans;
        for(int len = 2; len <= n; len++){
            left = 0;
            right = len - 1;
            while(right < n){
                int val = stoi(s.substr(left, right - left + 1));
                if(val < low){
                    left++;
                    right++;
                    continue;
                }
                if(val > high){
                    left++;
                    right++;
                    continue;
                }
                ans.push_back(val);
                left++;
                right++;
            }
        }

        // TC: O(1) — only 36 sequential digit numbers exist
        return ans;
    }
};