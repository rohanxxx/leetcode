class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        heap.push({nums[0], 0});
        int ans = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            // cout << "i: " << i << endl;
            // cout << "i - heap.top().second: " << i - heap.top().second << endl;
            while (i - heap.top().second > k) {
                heap.pop();
            }

            // cout << "heap.top().first: " << heap.top().first << endl;
            // cout << "heapSize: " << heap.size() << endl;
            int curr = max(0, heap.top().first) + nums[i];
            ans = max(ans, curr);
            heap.push({curr, i});
            
            // cout << "curr: " << curr << endl;
            // cout << "ans: " << ans << endl;
        }
        
        return ans;
    }
};