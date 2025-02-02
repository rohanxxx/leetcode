class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stack;
        unordered_map<int, int> mp;
        for(int num: nums2){
            if(stack.empty()){
                stack.push(num);
                continue;
            }
            while(!stack.empty() && stack.top() < num){
                mp[stack.top()] = num;
                stack.pop();
            }
            stack.push(num);
        }

        vector<int> ans;
        for(int num: nums1){
            if(mp.find(num) != mp.end()){
                ans.push_back(mp[num]);
                continue;
            }
            ans.push_back(-1);
        }
        return ans;
    }
};