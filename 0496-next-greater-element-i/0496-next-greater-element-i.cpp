class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, int> mp;
        
        for (int i = 0; i < nums2.size(); i++){
            mp[nums2[i]] = i;
        }
        
        for(auto n: nums1){
            int startIndex = mp[n];
            bool ifBreak = false;
            for(int i = startIndex; i < nums2.size(); i++){
                if(n < nums2[i]){
                    ans.push_back(nums2[i]);
                    ifBreak = true;
                    break;
                }
            }
            if(ifBreak == false){
                ans.push_back(-1);
            }
        }

        return ans;
    }
};